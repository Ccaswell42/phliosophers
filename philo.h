#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h> 
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		last_time_eat;
	pthread_t		thread;
	pthread_mutex_t  left_mut;
	pthread_mutex_t  right_mut;
}		t_philo;

typedef struct s_data
{
	int  num_philo;
	int  time_eat;
	int  time_sleep;
	int  time_death;
	t_philo		philo[200];
	pthread_mutex_t forks[200];
	pthread_mutex_t  print;

}	t_data;




int	ft_atoi(const char *str);
t_data	*init_data(char **argv);
void init_philo(t_data *data);
int create_philo(t_data *data);
void *func(void *data);
int init_mutex(t_data *data);
void init_forks(t_data *data);
#endif