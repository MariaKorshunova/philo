/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:59:42 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/23 16:33:37 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_invalid_number_arguments(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf(ANSI_COLOR_RED "Invalid number of arguments.\n\
Arguments should be:\n\
* number_of_philosophers\n* time_to_die\n* time_to_eat\n\
* time_to_sleep\n\
* [number_of_times_each_philosopher_must_eat]\n" ANSI_COLOR_RESET);
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}

void	error_arguments(void)
{
	printf(ANSI_COLOR_RED "Invalid arguments:\n\
Arguments should be:\n\
* number_of_philosophers: positive integer number\n\
* time_to_die: not negative integer number\n\
* time_to_eat: not negative integer number\n\
* time_to_sleep: not negative integer number\n\
* number_of_times_each_philosopher_must_eat: positive integer number\n"\
ANSI_COLOR_RESET);
}

void	error_memory(void)
{
	printf(ANSI_COLOR_RED "Memory error" ANSI_COLOR_RESET);
}
