#include "philo.h"
#include <unistd.h>

void	table_atributes_init(t_table *table, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		table->n_philo = ft_atou(argv[1]);
		table->t_die = ft_atou(argv[2]);
		table->t_eat = ft_atou(argv[3]);
		table->t_sleep = ft_atou(argv[4]);
		if (argc == 6)
			table->n_eats = ft_atou(argv[5]); 
	}
	else
	{
		printf("Bad amount of arguments");
		exit(1);
	}
}

void	philo_init(t_table *table, t_philo **philo)
{
	int	nphilo;
	int	*forks;

	nphilo = table->n_philo;
	forks = (int *) malloc(sizeof(int) * nphilo);
	if (forks)
	{
		table->forks = forks;
		*philo = (t_philo *) malloc(sizeof(t_philo) * (nphilo));
		if (*philo)
		{
			while (nphilo-- >= 1)
			{
				(*philo)[nphilo].table = table;
				(*philo)[nphilo].id = nphilo;
				(*philo)[nphilo].time = get_time();
			}
		}
		else
			clean(table, *philo, 1);
	}
	else 
		clean(table, *philo, 0);
}

void	threads_locks_allocate(t_table *table, t_philo *philo)
{
	table->threads = (pthread_t *) malloc(sizeof(pthread_t) * (table->n_philo + 1));
	table->locks = (pthread_mutex_t *) malloc(sizeof(pthread_t) * (table->n_philo + 1));
	if (!table->threads || !table->locks)
	{
		printf("ALLOCATING ERROR\n");
		clean(table, philo, 0);
	}
}

void	threads_init(t_table *table, t_philo *philo)
{
	pthread_t	*threads;
	int			nphilo;

	nphilo = table->n_philo;
	threads = table->threads;
	while (nphilo)
	{
		if (pthread_create(threads + nphilo, NULL, routine, philo + nphilo))
			clean(table, philo, 0);
		nphilo--;
	}
	if (pthread_create(threads, NULL, check_dead, &philo))
			clean(table, philo, 0);
}

void	locks_init(t_table *table, t_philo *philo)
{
	pthread_mutex_t	*locks;
	int				nphilo;

	locks = table->locks;
	nphilo = table->n_philo;
	while (nphilo)
	{
		if (pthread_mutex_init(locks + nphilo, NULL))
			locks_destroy(table, philo, nphilo);
		nphilo--;
	}
	if (pthread_mutex_init(locks, NULL))
		locks_destroy(table, philo, 0);
}
