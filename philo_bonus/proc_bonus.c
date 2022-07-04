/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:47 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/02 12:37:12 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*func_proc(void *philo)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)philo;
	i = 0;
	ph->last_time_eat = current_timestamp();
	if ((ph->id % 2) == 0)
		usleep(10000);
	pthread_create(&(ph->thread), NULL, thread_check_func, philo);
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
		if (ph->is_dead == 1)
			break ;
	}
	pthread_join(ph->thread, NULL);
	exit (0);
	return (NULL);
}

void	eating(t_philo *ph)
{
	t_data	*data;

	data = ph->inf;
	sem_wait(data->forks);
	print_message(data, ph, "has taken a fork");
	sem_wait(data->forks);
	print_message(data, ph, "has taken a fork");
	sem_wait(data->eat_check);
	ph->eat_count++;
	ph->last_time_eat = current_timestamp();
	sem_post(data->eat_check);
	print_message(data, ph, "is eating");
	ft_usleep(data->time_eat);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	sleeping(t_philo *ph)
{
	t_data	*data;

	data = ph->inf;
	print_message(data, ph, "is sleeping");
	ft_usleep(data->time_sleep);
}

void	thinking(t_philo *ph)
{
	t_data	*data;

	data = ph->inf;
	print_message(data, ph, "is thinking");
}
