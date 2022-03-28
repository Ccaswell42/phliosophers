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
	t_data			*data;
	pthread_t		thread;
}		t_philo;

typedef struct s_data
{
	int  num_philo;
	int  time_eat;
	int  time_sleep;
	int  time_death;
	t_philo		philo[200];
}	t_data;


int	ft_atoi(const char *str);

#endif