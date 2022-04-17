/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:21:34 by ccaswell          #+#    #+#             */
/*   Updated: 2022/04/08 12:25:31 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	d;
	int	c;

	c = 1;
	i = 0;
	d = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') \
			|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		c = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!((str[i] >= '0') && (str[i] <= '9')))
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		d = ((d * 10) + (str[i] - '0'));
		i++;
	}
	return (d * c);
}

long long	current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	all_join(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	if (pthread_join(data->death_check, NULL))
		return (1);
	while (i < data->num_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	all_detach(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	while (i < data->num_philo)
	{
		if (pthread_detach(philo[i].thread))
			return (1);
		i++;
	}
	return (0);
}

int	all_destroy(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	return (0);
}
