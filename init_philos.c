#include "philo.h"

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(data));
	if (!data)
		return (NULL);
	data->num_philo = ft_atoi(argv[1]);
	data->time_death = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	return (data);
}

void init_philo(t_data *data)
{
	int i;
	int n;
	int s;
	t_philo *ph;
	
	s = 1;
	n = data->num_philo;
	i = 0;
	ph = data->philo;
	while (i < n)
	{
		ph[i].id = s;
		ph[i].

	}
}



int create_philo(t_data *data)
{
	int num;
	int i;
	t_philo *philo;

	i = 0;
	philo = data->philo;

	while (i < data->num_philo)
	{
		if (pthread_create(&philo[i].thread, 0, func, &philo[i]))
			return (1);
		i++;

	}
}