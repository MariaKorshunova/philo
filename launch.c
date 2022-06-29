/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:13:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/29 20:43:59 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *argv);
static int	stop_simulation(t_data *data);

int	launch_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->time_start = time_stamp();
	while (i < data->number_of_philo)
	{
		if (pthread_create(&data->threads[i], NULL,
				philo_routine, &data->philo[i]))
		{
			error_description('t');
			free_all_data(data);
			return (EXIT_FAILURE);
		}
		pthread_detach(data->threads[i]);
		i++;
	}
	stop_simulation(data);
	return (EXIT_SUCCESS);
}

static void	*philo_routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->number_of_philo > 1)
		usleep((philo->time_to_eat / 2 * 1000) * ((philo->id + 1) % 2));
	while (1)
	{
		pthread_mutex_lock(philo->first_fork);
		print_status_philo(philo, "has taken a fork");
		pthread_mutex_lock(philo->second_fork);
		print_status_philo(philo, "has taken a fork");
		print_status_philo(philo, "is eating");
		pthread_mutex_lock(&(philo->data->print));
		philo->time_last_eat = time_stamp();
		pthread_mutex_unlock(&(philo->data->print));
		accurate_usleep(philo->time_to_eat);
		// pthread_mutex_lock(&(philo->data->print));
		// philo->number_eating += 1;
		// pthread_mutex_unlock(&(philo->data->print));
		pthread_mutex_unlock(philo->second_fork);
		pthread_mutex_unlock(philo->first_fork);
		print_status_philo(philo, "is sleeping");
		accurate_usleep(philo->time_to_sleep);
		print_status_philo(philo, "is thinking");
	}
	return (EXIT_SUCCESS);
}

static int	stop_simulation(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			//mutex
			if ((time_stamp() - data->philo[i].time_last_eat) >= data->time_to_die)
				//философ умер
				// мьютекс на принт остается залоченным
				return (-1);
			//mutex
			i++;
		}
	}
	return (0);
}
