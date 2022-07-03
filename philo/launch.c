/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:13:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/02 20:49:29 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *argv);
static void	philo_eating(t_philo *philo);

int	launch_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->time_start = time_stamp();
	while (i < data->number_of_philo)
	{
		data->philo[i].time_last_eat = data->time_start;
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
	while (philo->alive && philo->number_of_times_must_eat)
	{
		philo_eating(philo);
		print_status_philo(philo, "is sleeping");
		accurate_usleep(philo->time_to_sleep);
		usleep((philo->time_to_eat / 2 * 1000) * (philo->number_of_philo % 2));
		print_status_philo(philo, "is thinking");
	}
	return (EXIT_SUCCESS);
}

static void	philo_eating(t_philo *philo)
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
	pthread_mutex_lock(&(philo->data->print));
	philo->number_of_times_must_eat--;
	if (philo->number_of_times_must_eat == 0)
		philo->data->number_hungry_philo--;
	pthread_mutex_unlock(&(philo->data->print));
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}
