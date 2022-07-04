/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:19:47 by ccaswell          #+#    #+#             */
/*   Updated: 2022/04/12 16:51:58 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*die_checker(void *dasa)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *) dasa;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->philo[i].for_death);
		if (if_died(&data->philo[i]) == 1)
		{
			sub_check(data, data->philo[i].id);
			return (NULL);
		}
		pthread_mutex_unlock(&data->philo[i].for_death);
		if (if_ate(&data->philo[i]) == 1)
		{
			ft_usleep(9);
			all_detach(data);
			return (NULL);
		}
		i++;
		if (i == data->num_philo)
			i = 0;
	}
	return (NULL);
}

void	sub_check(t_data *data, int id)
{
	pthread_mutex_lock(&data->print);
	printf("%lld %d died\n", (current_timestamp() \
	- data->start_time), id);
	all_detach(data);
}

int	if_died(t_philo *ph)
{
	long long	nt;
	long long	ls;
	long long	dt;

	nt = current_timestamp();
	ls = ph->last_time_eat;
	dt = ph->inf->time_death;
	if ((nt - ls) > (dt + 2))
		return (1);
	return (0);
}

int	if_ate(t_philo *ph)
{
	int	a;
	int	b;
	int	c;
	int	d;

	pthread_mutex_lock(&ph->inf->last_time);
	a = ph->eat_count;
	pthread_mutex_unlock(&ph->inf->last_time);
	b = ph->inf->must_eat;
	c = ph->inf->eat_count;
	d = ph->inf->num_philo;
	if ((a == b) && (ph->flag_aet != 1))
	{
		ph->flag_aet = 1;
		ph->inf->eat_count++;
		c = ph->inf->eat_count;
	}
	if (c == d)
		return (1);
	return (0);
}
