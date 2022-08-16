#include "philo.h"


void	clean(t_table *table, t_philo *philo, int flag)
{
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
