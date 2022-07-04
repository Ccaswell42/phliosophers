/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:19:02 by ccaswell          #+#    #+#             */
/*   Updated: 2022/06/02 12:35:19 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_bill(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		kill(data->philo[i].pid, 15);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		err;

	data = malloc(sizeof(*data));
	if (!data)
		return (0);
	err = init_data(argc, argv, data);
	if (err)
		return (err);
	create_philo(data);
}
