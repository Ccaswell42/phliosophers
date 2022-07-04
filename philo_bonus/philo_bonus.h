/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:52 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/02 12:40:08 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long		last_time_eat;
	pthread_t		thread;
	struct s_data	*inf;
	pid_t			pid;
	int				is_dead;
	int				is_eat;
}		t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_eat;
	int				time_sleep;
	int				time_death;
	int				must_eat;
	long long		start_time;
	t_philo			*philo;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*eat_check;
	sem_t			*dead_check;
	sem_t			*flag_eat;
}	t_data;

int			ft_atoi(const char *str);
long long	current_timestamp(void);
void		ft_usleep(long long time);
int			init_data(int argc, char **argv, t_data *data);
int			init_philo(t_data *data);
void		*thread_check_func(void *philo);
int			check_death(t_philo *ph);
int			check_eat_ph(t_philo *ph);
void		*func_proc(void *philo);
void		eating(t_philo *ph);
void		sleeping(t_philo *ph);
void		thinking(t_philo *ph);
int			create_philo(t_data *data);
void		exit_launch(t_data *data);
int			init_sems(t_data *data);
void		print_message(t_data *data, t_philo *ph, char *str);
void		close_sems(t_data *data);
void		kill_bill(t_data *data);
void		meal_sems(t_data *data);
void		eat_launch(t_data *data);

#endif