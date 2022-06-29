/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:13:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/29 16:43:23 by jmabel           ###   ########.fr       */
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
	if (init_mutex(data))
		return (EXIT_FAILURE);
	init_philo(data);
	return (EXIT_SUCCESS);
}

static int	malloc_threads_forks(t_data *data)
{
	data->threads = (pthread_t *)malloc(data->number_of_philo
			* sizeof(pthread_t));
	if (data->threads == NULL)
	{
		error_description('m');
		free(data);
		return (EXIT_FAILURE);
	}
	data->forks = (pthread_mutex_t *)malloc(data->number_of_philo
			* sizeof(pthread_mutex_t));
	if (data->forks == NULL)
	{
		error_description('m');
		free(data->threads);
		free(data);
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
		error_description('m');
		free(data->threads);
		free(data->forks);
		free(data);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->print, NULL))
	{
		free_all_data(data);
		return (EXIT_FAILURE);
	}
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
