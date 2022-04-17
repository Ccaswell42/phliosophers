/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:22:59 by ccaswell          #+#    #+#             */
/*   Updated: 2022/04/12 16:52:35 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if ((argc != 5) && (argc != 6))
		return (1);
	data = all_init(argc, argv);
	if (!data)
	{
		free(data);
		return (1);
	}
	all_join(data);
	free(data);
}
