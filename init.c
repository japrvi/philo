#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

void	table_atributes_init(t_table *table, int argc, char **argv)
{
	if (argc == 4 || argc == 5)
	{
		table->n_philo = ft_atou(argv[0]);
		table->t_die = ft_atou(argv[1]);
		table->t_eat = ft_atou(argv[2]);
		table->t_sleep = ft_atou(argv[3]);
		if (argc == 5)
			table->n_eats = ft_atou(argv[4]); 
	}
	else
	{
		printf("Bad amount of arguments");
		exit(1);
	}
}

void	philo_init(t_table *table, t_philo *philo)
{
	int	nphilo;
	int	*forks;

	forks = (int *) malloc(sizeof(int) * nphilo);
	if (forks)
	{
		nphilo = table->n_philo;
		while (nphilo--)
		{
			philo[nphilo].table = table;
			philo[nphilo].id = nphilo;
			philo[nphilo].time = get_time();
		}
	}
}

void	threads_locks_allocate(t_table *table, t_philo *philo)
{
	table->threads = (pthread_t *) malloc(sizeof(pthread_t) * (table->n_philo + 1));
	table->locks = (pthread_mutex_t *) malloc(sizeof(pthread_t) * (table->n_philo + 1));
	if (table->threads || table->locks)
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
	while (nphilo--)
	{
		if (pthread_create(threads + nphilo, NULL, routine, philo + nphilo))
			threads_destroy(threads, nphilo);
	}
}

void	locks_init(t_table *table, t_philo *philo)
{
}
