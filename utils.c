#include "philo.h"

static int	isNumeric(char c)
{
	return (c >= '0' && c <= '9');
}

void	print_state(t_table *table, t_philo *philo)
{
	printf("Table info:\n");
	printf("Number of philosophers: %d\n", table->n_philo);
	printf("Time to die: %d\n", table->t_die);
	printf("Time to eat: %d\n", table->t_eat);
	printf("Time to sleep: %d\n", table->t_sleep);
	printf("Times must eat: %d\n", table->n_eats);
	printf("Philo info %p\n", philo);
	printf("Dead = %i\n", table->dead);
	for (int i = 0; i < table->n_philo; i++)
	{
		printf("ID: %d\tTIME: %li\t TABLE:%p\n", philo[i].id, (get_time() - philo[i].time), philo[i].table);
	}
	printf("LOCKS: %p\t THREADS: %p\t", table->threads, table->locks);
}

int	ft_atou(char *str)
{
	int	i;
	int	res;

	res = 0;
	if (isNumeric(str[0]))
	{
		i = 0;
		while (isNumeric(str[i]) && str[i])
		{
			res = res * 10 + (str[i] - '0');
			i++;
		}
	}
	else
	{
		printf("Bad Arguments");
		exit(1);
	}
	return (res);
}

long int	get_time()
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
