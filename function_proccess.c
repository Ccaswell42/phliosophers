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
		if (ph->inf->death_flag == 1)
			break;
		pthread_mutex_lock(ph->min_mut);
		pthread_mutex_lock(&ph->inf->print);
		printf("%lld %d has taken a fork\n", (current_timestamp()- ph->inf->start_time), ph->id);
		pthread_mutex_unlock(&ph->inf->print);
		pthread_mutex_lock(ph->max_mut);
		pthread_mutex_lock(&ph->inf->print);
		printf("%lld %d has taken a fork\n", (current_timestamp()- ph->inf->start_time), ph->id);
		printf("%lld %d is eating\n", (current_timestamp()- ph->inf->start_time), ph->id);
		pthread_mutex_unlock(&ph->inf->print);
		usleep(ph->inf->time_eat);
		pthread_mutex_unlock(ph->min_mut);
		pthread_mutex_unlock(ph->max_mut);
		pthread_mutex_lock(&ph->inf->last_time);///////
		ph->last_time_eat = current_timestamp();
		pthread_mutex_unlock(&ph->inf->last_time);/////
		pthread_mutex_lock(&ph->inf->print);
		printf("%lld %d is sleeping\n", (current_timestamp()- ph->inf->start_time), ph->id);
		pthread_mutex_unlock(&ph->inf->print);
		usleep(ph->inf->time_sleep);
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
	if (pthread_join(data->death_check, NULL))
			return (1);
	while (i < data->num_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

void *die_checker(void *dasa)
{
	long long a;
 	long long b, c, d;
	int i;
	t_data *data;

	data = (t_data *) dasa;
	i = 0;
	a = (data->time_death / 1000);

	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->last_time);
	 	b = (data->philo[i].last_time_eat);
	 	c = current_timestamp() - b;
		 d = (data->time_eat / 1000);
		 pthread_mutex_unlock(&data->last_time);
		if ((c - a) > d)
		{
			printf("LOGOS_a %d: %lld\n", data->philo[i].id, a);
			printf("LOGOS_b %d: %lld\n", data->philo[i].id, b);
			printf("LOGOS_c %d: %lld\n", data->philo[i].id, c);
			printf("LOGOS_d %d: %lld\n", data->philo[i].id, d);
			pthread_mutex_lock(&data->for_death);
			data->death_flag = 1;
			pthread_mutex_unlock(&data->for_death);
			printf("%lld %d died\n", (current_timestamp()- data->start_time), data->philo[i].id);
			//exit (0);
			break ;
		}
		i++;
		if (i == data->num_philo)
			i = 0;
	}
	return (0);
}




// void die_check(t_philo *philo)
// {
// 	long long a;
// 	long long b, c, d;

// 	a = (philo->inf->time_death / 1000);
// 	c = (philo->last_time_eat);
// 	b = current_timestamp() - philo->inf->start_time;
// 	d = b - c;
// 	printf("LOGOS_c %d: %lld\n",philo->id, c);
// 	printf("LOGOS_b %d: %lld\n",philo->id, b);
// 	printf("LOGOS_a %d: %lld\n",philo->id, a);
// 	printf("LOGOS_d %d: %lld\n",philo->id, d);
// 	if (d > a)
// 	{
// 		printf ("%lld %d died\n", (current_timestamp()- philo->inf->start_time), philo->id);
// 		all_join(philo->inf);
// 		exit (0);
// 	}
// }
