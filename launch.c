/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:13:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/28 12:01:21 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	return (EXIT_SUCCESS);
}

int	launch_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_create(&data->threads[i], NULL,
				philo_routine, &data->philo[i]))
		{
			error_function('t');
			free_all_data(data);
			return (EXIT_FAILURE);
		}
		pthread_detach(data->threads[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
