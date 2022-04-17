/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:43:59 by ccaswell          #+#    #+#             */
/*   Updated: 2022/04/12 16:23:34 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h> 
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		last_time_eat;
	int				flag_aet;
	pthread_t		thread;
	pthread_mutex_t	*max_mut;
	pthread_mutex_t	*min_mut;
	pthread_mutex_t	for_death;
	struct s_data	*inf;
}		t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_eat;
	int				time_sleep;
	int				time_death;
	int				must_eat;
	int				eat_count;
	long long		start_time;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	print;
	pthread_t		death_check;
	int				death_flag;
	pthread_mutex_t	last_time;
}	t_data;

int			ft_atoi(const char *str);
t_data		*init_data(char **argv, int argc);
void		init_philo(t_data *data);
int			create_philo(t_data *data);
void		*func(void *data);
int			init_mutex(t_data *data);
void		init_forks(t_data *data);
t_data		*all_init(int argc, char **argv);
int			all_join(t_data *data);
int			all_detach(t_data *data);
int			all_destroy(t_data *data);
long long	current_timestamp(void);
void		*die_checker(void *dasa);
void		eating(t_philo *ph);
void		sleeping(t_philo *ph);
void		thinking(t_philo *ph);
int			if_died(t_philo *ph);
int			if_ate(t_philo *ph);
void		ft_usleep(long long time);
void		sub_check(t_data *data, int id);
int			valid_args(t_data *data);
#endif