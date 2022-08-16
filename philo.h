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
	int			id;
	int			alive;
	long int	time;
	t_table		*table;
}	t_philo;

//Funcion para obtener la hora.
long int	get_time();

//Utilidades
int			ft_atou(char *str);
void		print_state(t_table *table, t_philo *philo);

//Funciones para inicializar el estado del recurso compartido
void		table_atributes_init(t_table *table, int argc, char **argv);
void		philo_init(t_table *table, t_philo *philo);
void		threads_locks_allocate(t_table *table, t_philo *philo);
void		threads_locks_init(t_table *table, t_philo *philo);

//Funciones para limpiar 
void		clean(t_table *table, t_philo *philo, int flag);
void		threads_locks_clean(t_table *table, t_philo *philo, int it_t, int it_l);
void		threads_destroy(t_table *table, t_philo *philo, int pos);
void		locks_destroy(t_table *table, t_philo *philo, int pos);

//Funcion a ejecutar
void	*routine(void *arg);
void	*check_dead(void *arg);
#endif
