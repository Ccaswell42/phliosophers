#include "philo.h"

void *func(void *data)
{
	usleep(1000);
	t_philo *ph;
	ph = (t_philo *)data;
	if ((ph->id % 2) == 0)
			usleep(25000);
	while (1)
	{
		pthread_mutex_lock(ph->min_mut);
		pthread_mutex_lock(ph->max_mut);
		printf("Philo %d is eating\n", ph->id);
		usleep(ph->inf->time_eat);
		pthread_mutex_unlock(ph->min_mut);
		pthread_mutex_unlock(ph->max_mut);
		printf("Philo %d is sleeping\n", ph->id);
		usleep(ph->inf->time_sleep);
	}

	return (NULL);
}

int all_join(t_data *data)
{
	int i;
	t_philo *philo;

	i = 0;
	philo = data->philo;

	while (i < data->num_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}