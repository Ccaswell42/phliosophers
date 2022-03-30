#include "philo.h"


int main(int argc, char **argv)
{
	if ((argc != 5) && (argc != 6))
		return (1);
	t_data *data;

	data = init_data(argv);
	init_philo(data);
	printf("NACHALO:\n");
	init_mutex(data);
	init_forks(data);

	create_philo(data);
	all_join(data);
	printf("KONEC\n");
	free(data);
}

// printf("%p\n", data->philo[0].left_mut);
	//  printf("%p\n", data->philo[0].right_mut);
	// printf("%p\n", &data->forks[0]);
	// printf("%p\n", &data->forks[1]);
	// printf("%p\n", &data->forks[2]);
	// printf("%p\n", &data->forks[3]);
	// printf("%p\n", &data->forks[4]);