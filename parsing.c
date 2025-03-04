/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:09:18 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/04 16:28:22 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* PARSING
here we will parse the input from the user
we check for:
- valid, positive, numerical arguments
- not bigger than INT_MAX
- timestamps >= 60ms
*/

/* VALID INPUT
	valid input ex. 5 800 200 200 [3]
	num of philos
	time to die
	time to eat
	time to sleep
	limit of meals [optional]
*/

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*num;

	num = NULL;
	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		perror_exit("Cannot use negative numbers\n");
	if (!is_digit(*str))
		perror_exit("Only digits allowed\n");
	num = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		perror_exit("Value is bigger than 2147483647\n");
	return (num);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
		num = num * 10 + (*str - '0');
	if (num > INT_MAX)
		perror_exit("Value is bigger than 2147483647\n");
	return (num);
}

void	parse_input(t_input *input, char **argv)
{
	input->num_of_philos = ft_atol(argv[1]);
	input->time_to_die = ft_atol(argv[2]) * 1000;
	input->time_to_eat = ft_atol(argv[3]) * 1000;
	input->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (input->time_to_die < 60000
		|| input->time_to_eat < 60000
		|| input->time_to_sleep < 60000)
		perror_exit("Timestamps must be at least 60ms\n");
	if (argv[5])
		input->must_eat = ft_atol(argv[5]);
	else
		input->must_eat = -1;
}
