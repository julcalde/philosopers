/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:02:57 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/04 14:16:33 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	valid input ex. 5 800 200 200 [3]
	num of philos
	time to die
	time to eat
	time to sleep
	optional limit of meals
*/

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		printf("nice caulc\n");
	}
	else
	{
		perror_exit("Invalid input\nCorrect input example:\n\
./philo 5 800 200 200 3");
	}
	return (0);
}

/* Philosophers with threads and mutexes
	Program name:		philo
	Turn in files:		Makefile, *.h, *.c, in directory philo/
	Makefile:			NAME, all, clean, fclean, re
	Arguments:			number_of_philosophers, time_to_die time_to_eat,
						time_to_sleep,
						[number_of_times_each_philosopher_must_eat]
	External functs:	memset, printf, malloc, free, write, usleep,
						gettimeofday, pthread_create, pthread_detach,
						pthread_join, pthread_mutex_init,
						pthread_mutex_destroy, pthread_mutex_lock,
						pthread_mutex_unlock.
	Libft authorized:	No
*/
