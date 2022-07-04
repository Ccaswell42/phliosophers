/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:27:24 by ccaswell          #+#    #+#             */
/*   Updated: 2022/04/12 16:25:59 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(char **argv, int argc)
{
	t_data	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (NULL);
	data->start_time = current_timestamp();
	data->num_philo = ft_atoi(argv[1]);
	data->time_death = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->death_flag = 0;
	data->eat_count = 0;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = 2147483647;
	if (pthread_mutex_init(&data->last_time, 0))
		return (NULL);
	return (data);
}

void	init_philo(t_data *data)
{
	int		i;
	int		n;
	int		s;
	t_philo	*ph;

	s = 1;
	n = data->num_philo;
	i = 0;
	ph = data->philo;
	while (i < n)
	{
		ph[i].id = s;
		if (s != 1)
			ph[i].right_fork = (s - 1);
		else
			ph[i].right_fork = n;
		ph[i].left_fork = s;
		ph[i].inf = data;
		ph[i].last_time_eat = ph->inf->start_time;
		ph[i].eat_count = 0;
		ph[i].flag_aet = 0;
		i++;
		s++;
	}
}

int	create_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	while (i < data->num_philo)
	{
		if (pthread_create(&philo[i].thread, 0, func, &philo[i]))
			return (0);
		i++;
	}
	if (pthread_create(&data->death_check, 0, die_checker, data))
		return (0);
	return (1);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], 0))
			return (0);
		if (pthread_mutex_init(&data->philo[i].for_death, 0))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->print, 0))
		return (0);
	return (1);
}

void	init_forks(t_data *data)
{
	int		i;
	int		n;
	int		s;
	t_philo	*ph;

	s = 1;
	n = data->num_philo;
	i = 0;
	ph = data->philo;
	while (i < n)
	{
		if (s != 1)
		{
			ph[i].min_mut = &data->forks[i - 1];
			ph[i].max_mut = &data->forks[i];
		}
		else
		{
			ph[i].min_mut = &data->forks[0];
			ph[i].max_mut = &data->forks[n - 1];
		}
		i++;
		s++;
	}
}
