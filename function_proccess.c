#include "philo.h"

void *func(void *data)
{
	usleep(1000);
	t_philo *ph;
	ph = (t_philo *)data;
	int i;
	i = ph->id;
	printf("ID procc is: %d\n", i);
	return (NULL);
}