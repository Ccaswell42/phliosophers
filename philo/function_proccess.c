/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_proccess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:21:25 by ccaswell          #+#    #+#             */
/*   Updated: 2022/04/12 16:24:07 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *data)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)data;
	i = 0;
	if ((ph->id % 2) == 0)
		usleep(25000);
	while (1)
	{
		eating(ph);
		sleeping(ph);
		thinking(ph);
	}
	return (NULL);
}

void	eating(t_philo *ph)
{
	pthread_mutex_lock(ph->min_mut);
	pthread_mutex_lock(&ph->inf->print);
	printf("%lld %d has taken a fork\n", (current_timestamp() \
	- ph->inf->start_time), ph->id);
	pthread_mutex_unlock(&ph->inf->print);
	pthread_mutex_lock(ph->max_mut);
	pthread_mutex_lock(&ph->for_death);
	pthread_mutex_lock(&ph->inf->print);
	printf("%lld %d has taken a fork\n", (current_timestamp() \
	- ph->inf->start_time), ph->id);
	pthread_mutex_unlock(&ph->inf->print);
	pthread_mutex_lock(&ph->inf->print);
	printf("%lld %d is eating\n", (current_timestamp() \
	- ph->inf->start_time), ph->id);
	pthread_mutex_unlock(&ph->inf->print);
	ph->last_time_eat = current_timestamp();
	pthread_mutex_lock(&ph->inf->last_time);
	ph->eat_count++;
	pthread_mutex_unlock(&ph->inf->last_time);
	pthread_mutex_unlock(&ph->for_death);
	ft_usleep((ph->inf->time_eat));
	pthread_mutex_unlock(ph->max_mut);
	pthread_mutex_unlock(ph->min_mut);
}

void	sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->print);
	printf("%lld %d is sleeping\n", (current_timestamp() \
	- ph->inf->start_time), ph->id);
	pthread_mutex_unlock(&ph->inf->print);
	ft_usleep((ph->inf->time_sleep));
}

void	thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->print);
	printf("%lld %d is thinking\n", (current_timestamp() \
	- ph->inf->start_time), ph->id);
	pthread_mutex_unlock(&ph->inf->print);
}
