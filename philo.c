/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:02:57 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/04 16:22:41 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* MAIN SHOULD
DONE check for correct num of inputs
DONE if so, check for correct inputs and parse them
TODO if so, initialize the input for structs
TODO if so, start the simulation until a philo dies or limit of meals is reached
TODO at the end, clean up and exit
*/
int	main(int argc, char **argv)
{
	t_input	*input;

	input = NULL;
	if (argc == 5 || argc == 6)
	{
		parse_input(input, argv);
	}
	else
		perror_exit("Invalid input\nCorrect input example:\n\
./philo 5 800 200 200 [3]");
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
