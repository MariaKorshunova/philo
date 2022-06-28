/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:13:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/28 11:06:40 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	malloc_threads_forks(t_data *data);
static int	malloc_philo(t_data *data);
static int	init_mutex(t_data *data);

int	init_simulation(t_data *data)
{
	if (malloc_threads_forks(data))
		return (EXIT_FAILURE);
	if (malloc_philo(data))
		return (EXIT_FAILURE);
	init_philo(data);
	if (init_mutex(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	malloc_threads_forks(t_data *data)
{
	data->threads = (pthread_t *)malloc(data->number_of_philo
			* sizeof(pthread_t));
	if (data->threads == NULL)
	{
		error_function('m');
		return (EXIT_FAILURE);
	}
	data->forks = (pthread_mutex_t *)malloc(data->number_of_philo
			* sizeof(pthread_mutex_t));
	if (data->forks == NULL)
	{
		error_function('m');
		free(data->threads);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	malloc_philo(t_data *data)
{
	data->philo = (t_philo *)malloc(data->number_of_philo
			* sizeof(t_philo));
	if (data->philo == NULL)
	{
		error_function('m');
		free(data->threads);
		free(data->forks);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			error_mutex_fork_init(data, i);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
