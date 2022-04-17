/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:24:06 by ccaswell          #+#    #+#             */
/*   Updated: 2022/04/12 16:52:24 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*all_init(int argc, char **argv)
{
	t_data	*data;

	data = init_data(argv, argc);
	if (!data)
		return (NULL);
	if (!(valid_args(data)))
		return (NULL);
	init_philo(data);
	if (!(init_mutex(data)))
		return (NULL);
	init_forks(data);
	if (!(create_philo(data)))
		return (NULL);
	return (data);
}

void	ft_usleep(long long time)
{
	long long	stop;

	stop = current_timestamp() + time;
	while (current_timestamp() < stop)
		usleep(1);
}

int	valid_args(t_data *data)
{
	if (!(data->num_philo))
		return (0);
	if (!(data->time_death))
		return (0);
	if (!(data->time_eat))
		return (0);
	if (!(data->time_sleep))
		return (0);
	return (1);
}
