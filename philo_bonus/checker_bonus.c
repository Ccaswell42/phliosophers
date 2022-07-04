/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:35 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/02 12:30:33 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*thread_check_func(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		check_death(ph);
		usleep(1000);
		check_eat_ph(ph);
	}	
	return (0);
}

int	check_death(t_philo *ph)
{
	t_data	*data;

	data = ph->inf;
	sem_wait(data->eat_check);
	if (current_timestamp() - ph->last_time_eat > data->time_death + 5)
	{
		print_message(data, ph, "is dead");
		sem_wait(data->print);
		sem_post(data->eat_check);
		exit(1);
	}
	sem_post(data->eat_check);
	return (0);
}

int	check_eat_ph(t_philo *ph)
{
	t_data	*data;

	data = ph->inf;
	sem_wait(data->eat_check);
	if (data->must_eat != -1 && ph->eat_count >= data->must_eat \
	&& ph->is_eat != 1)
	{
		ph->is_eat = 1;
		sem_post(data->forks);
		sem_post(data->forks);
		sem_post(data->flag_eat);
		sem_post(data->eat_check);
		exit (0);
		return (1);
	}
	sem_post(data->eat_check);
	return (0);
}
