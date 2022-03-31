#include "philo.h"

int main()
{
    struct timeval	tv;
    int t;

 	t = gettimeofday(&tv, NULL);
     printf ("%ld\n", tv.tv_sec);
}

// long long	get_timestamp(void)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
// }
//http://www.ccfit.nsu.ru/~kireev/lab1/lab1time.htm
