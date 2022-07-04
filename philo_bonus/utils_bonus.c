/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:24:57 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/02 12:37:58 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_usleep(long long time)
{
	long long	stop;

	stop = current_timestamp() + time;
	while (current_timestamp() < stop)
		usleep(1);
}

void	print_message(t_data *data, t_philo *ph, char *str)
{
	sem_wait(data->print);
	printf("%lld %d %s\n", (current_timestamp() - data->start_time) \
	, ph->id, str);
	sem_post(data->print);
}

void	close_sems(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->eat_check);
	sem_close(data->dead_check);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("meal_check");
	sem_unlink("dead_check");
}
