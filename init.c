/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:13:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/23 17:00:25 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_threads(t_data *data)
{
	data->threads = (pthread_t *)malloc(data->number_of_philo
			* sizeof(pthread_t));
	if (data->threads == NULL)
	{
		error_memory();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_forks(t_data *data)
{
	data->forks = (pthread_mutex_t *)malloc(data->number_of_philo
			* sizeof(pthread_mutex_t));
	if (data->forks == NULL)
	{
		error_memory();
		free(data->threads);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_simulation(t_data *data)
{
	if (init_threads(data))
		return (EXIT_FAILURE);
	if (init_forks(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
