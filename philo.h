/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:02:52 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/04 16:22:07 by julcalde         ###   ########.fr       */
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

typedef struct s_input	t_input;

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
	long	num_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	must_eat;
	long	time_start;
	long	time_end;
	t_fork	*forks;
	t_philo	*philos;
}			t_input;

/*
	FUNCTIONS
*/
//	utils.c
void	perror_exit(const char *err_msg);

// parsing.c
void	parse_input(t_input *input, char **argv);

#endif