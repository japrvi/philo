#include "philo.h"

int	main(int argc, char **argv)
{
	static t_table	table;
	static t_philo	*philo;

	table_atributes_init(&table, argc, argv);
	philo_init(&table, &philo);
	threads_locks_allocate(&table, philo);
	locks_init(&table, philo);
//	threads_init(&table, philo);
	print_state(&table, philo);
	clean(&table, philo, 1);
	exit(0);
}
