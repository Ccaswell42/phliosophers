/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:23:46 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/02 12:33:08 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(int argc, char **argv, t_data *data)
{
	if ((argc != 5) && (argc != 6))
		return (1);
	data->num_philo = ft_atoi(argv[1]);
	data->time_death = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	if ((data->must_eat == 0) || (init_sems(data)))
		return (1);
	if (init_philo(data))
		return (1);
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (1);
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].inf = data;
		data->philo[i].last_time_eat = current_timestamp();
		data->philo[i].eat_count = 0;
		data->philo[i].is_dead = 0;
		data->philo[i].is_eat = 0;
		i++;
	}
	return (0);
}

int	init_sems(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("meal_check");
	sem_unlink("dead_check");
	sem_unlink("flag_eat");
	data->flag_eat = sem_open("flag_eat", O_CREAT, S_IRWXU, data->num_philo);
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, data->num_philo);
	data->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	data->eat_check = sem_open("meal_check", O_CREAT, S_IRWXU, 1);
	data->dead_check = sem_open("dead_check", O_CREAT, S_IRWXU, 1);
	meal_sems(data);
	if (data->forks <= 0 || data->print <= 0 || data->eat_check <= 0
		|| data->dead_check <= 0)
		return (1);
	return (0);
}

void	meal_sems(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		sem_wait(data->flag_eat);
		i++;
	}
}
