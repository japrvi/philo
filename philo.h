#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>

typedef struct	s_table
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eats;
	int				*forks;
	pthread_t		*threads;
	pthread_mutex_t	*locks;
}	t_table;

typedef struct	s_philo
{
	int		id;
	long	time;
	t_table	*table;
}	t_philo;

//Funcion para obtener la hora.
long	get_time();

//Utilidades
int		ft_atou(char *str);
void	print_state(t_table *table, t_philo *philo);

//Funciones para inicializar el estado del recurso compartido
t_table	table_atributes_init(int argc, char **argv);
t_philo	*philo_init(t_table *table);
void	threads_locks_allocate(t_table *table, t_philo *philo);
void	threads_locks_init(t_table *table, t_philo *philo);
//Funciones para limpiar 
void	clean(t_table *table, t_philo *philo, int flag);
void	threads_locks_clean(t_table *table, t_philo *philo, int it_t, int it_l);
void	threads_locks_destroy(t_table *table, t_philo *philo, int it_t, int it_l);

//Funcion a ejecutar
void	*routine(void *arg);
void	*check_dead(void *arg);
#endif
