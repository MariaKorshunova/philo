/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:47:19 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/03 19:00:14 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (error_invalid_number_arguments(argc))
		return (EXIT_FAILURE);
	if (parse_arguments(data, argv))
		return (EXIT_FAILURE);
	if (init_simulation(data))
		return (EXIT_FAILURE);
	if (launch_simulation(data))
		return (EXIT_FAILURE);
	close_semaphore("print", &data->print);
	close_semaphore("forks", &data->forks);
	return (EXIT_SUCCESS);
}
