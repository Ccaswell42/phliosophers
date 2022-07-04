/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:28:38 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/02 12:31:26 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_philo(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = current_timestamp();
	while (i < data->num_philo)
	{
		data->philo[i].pid = fork();
		if (data->philo[i].pid < 0)
			return (1);
		if (data->philo[i].pid == 0)
			func_proc(&data->philo[i]);
		i++;
	}
	eat_launch(data);
	return (0);
}

void	eat_launch(t_data *data)
{
	int	i;
	int	b;

	i = 0;
	waitpid(-1, &b, 0);
	if (b != 0)
	{
		kill_bill(data);
		close_sems(data);
		exit (0);
	}
	while (i < data->num_philo)
	{
		sem_wait(data->flag_eat);
		i++;
	}
	kill_bill(data);
	close_sems(data);
	exit (0);
}
