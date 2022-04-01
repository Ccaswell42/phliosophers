#include "philo.h"

void *func(void *data)
{
	usleep(1000);
	t_philo *ph;
	ph = (t_philo *)data;
	int i;
	i = 0;
	if ((ph->id % 2) == 0)
			usleep(25000);
	while (1)
	{
		
		pthread_mutex_lock(ph->min_mut);
		printf("%lld %d has taken a fork\n", (current_timestamp()- ph->inf->start_time), ph->id);
		pthread_mutex_lock(ph->max_mut);
		printf("%lld %d has taken a fork\n", (current_timestamp()- ph->inf->start_time), ph->id);
		printf("%lld %d is eating\n", (current_timestamp()- ph->inf->start_time), ph->id);
		if (i != 0)
			die_check(ph);
		usleep(ph->inf->time_eat);
		pthread_mutex_unlock(ph->min_mut);
		pthread_mutex_unlock(ph->max_mut);
		
		printf("%lld %d is sleeping\n", (current_timestamp()- ph->inf->start_time), ph->id);
		pthread_mutex_lock(ph->pront);///////
		ph->last_time_eat = current_timestamp() - ph->inf->start_time;
		pthread_mutex_unlock(ph->pront);/////
		usleep(ph->inf->time_sleep);
		//printf("ID: %d last_time %lld\n", ph->id, ph->last_time_eat);
		i++;
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

void die_check(t_philo *philo)
{
	long long a;
	long long b, c, d;

	a = (philo->inf->time_death / 1000);
	c = (philo->last_time_eat);
	b = current_timestamp() - philo->inf->start_time;
	d = b - c;
	printf("LOGOS_c %d: %lld\n",philo->id, c);
	printf("LOGOS_b %d: %lld\n",philo->id, b);
	printf("LOGOS_a %d: %lld\n",philo->id, a);
	printf("LOGOS_d %d: %lld\n",philo->id, d);
	if (d > a)
	{
		printf ("%lld %d died\n", (current_timestamp()- philo->inf->start_time), philo->id);
		all_join(philo->inf);
		exit (0);
	}
}