/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:02:52 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/04 14:46:47 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

/*
	STRUCTURES
*/
typedef pthread_mutex_t	t_mutex;

typedef struct s_fork
{
	t_mutex	fork;
	int		fork_id;
}			t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_count;
	long		last_meal;
	bool		happy_belly;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_input		*input;
}			t_philo;

typedef struct s_input
{
	long	num_of_philos; //argv[1]
	long	time_to_die; //argv[2]
	long	time_to_eat; //argv[3]
	long	time_to_sleep; //argv[4]
	long	num_of_meals; //argv[5] ()== -1 if no limit)
	long	time_start; //gettimeofday for timestamps
	long	time_end; //getttimeofday for death or limit if meal reached
	t_fork	*forks; //array of fork mutexes
	t_philo	*philos; //array of philo threads
}			t_input;

/*
	FUNCTIONS
*/
//	utils.c
void	perror_exit(const char *err_msg);


#endif