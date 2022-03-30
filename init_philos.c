#include "philo.h"

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(data));
	if (!data)
		return (NULL);
	data->num_philo = ft_atoi(argv[1]);
	data->time_death = (ft_atoi(argv[2]) * 1000);
	data->time_eat = (ft_atoi(argv[3])* 1000);
	data->time_sleep = (ft_atoi(argv[4])* 1000);
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
		if (s != 1)
			ph[i].right_fork = (s - 1);
		else 
			ph[i].right_fork = n;
		ph[i].left_fork = s;
		ph[i].inf = data;
		ph[i].last_time_eat = 1488; ////
		i++;
		s++;
	}
}

int create_philo(t_data *data)
{
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
	return (0);
}

int init_mutex(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], 0))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, 0))
			return (1);
	return (0);
}

void init_forks(t_data *data)
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
		ph[i].pront = &data->print;
		i++;
		s++;
	}
}