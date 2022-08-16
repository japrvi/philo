#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>


void	clean(t_table *table, t_philo *philo, int flag)
{
	table->dead = 1;
	if (flag == 1)
		locks_destroy(table, philo, table->n_philo);
	if (table->threads)
		free(table->threads);
	if (table->locks)
		free(table->locks);
	if (table->forks)
		free(table->forks);
	exit(1);
}

void	locks_destroy(t_table *table, t_philo *philo, int pos)
{
	const int		nphilo = table->n_philo;
	pthread_mutex_t	*locks;

	locks = table->locks;
	while (++pos <= nphilo)
		pthread_mutex_destroy(locks + pos);
	clean(table, philo, 0);
}
