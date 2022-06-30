/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:53:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/30 11:20:47 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_main_info_to_philo(t_data *data, t_philo *philo);
static void	init_mutex_to_philo(t_data *data, t_philo *philo, int i);

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].id = i;
		data->philo[i].data = data;
		data->philo[i].alive = 1;
		init_main_info_to_philo(data, &data->philo[i]);
		init_mutex_to_philo(data, &data->philo[i], i);
		i++;
	}
}

static void	init_main_info_to_philo(t_data *data, t_philo *philo)
{
	philo->number_of_philo = data->number_of_philo;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->number_of_times_must_eat = data->number_of_times_must_eat;
}

static void	init_mutex_to_philo(t_data *data, t_philo *philo, int i)
{
	if (i % 2 == 0)
	{
		philo->first_fork = &data->forks[(i + 1) % data->number_of_philo];
		philo->second_fork = &data->forks[i];
	}
	else
	{
		philo->first_fork = &data->forks[i];
		philo->second_fork = &data->forks[(i + 1) % data->number_of_philo];
	}
}
