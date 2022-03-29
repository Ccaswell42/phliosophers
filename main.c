#include "philo.h"


int main(int argc, char **argv)
{
	if ((argc != 5) && (argc != 6))
		return (1);
	t_data *data;

	data = init_data(argv);
	init_philo(data);
	printf("NACHALO:\n");
	init_forks(data);

	printf("KONEC\n");
	free(data);
}