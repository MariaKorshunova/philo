/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_processes_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:38:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/04 17:23:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_routine(t_data *data);
static int	check_is_full(t_data *data);
static int	check_is_dead(t_data *data);

int	philo_processes(t_data *data)
{
	pthread_t	check;

	if (child_create_semaphore(data))
		exit (1);
	if (pthread_create(&check, NULL, stop_simulation, data))
	{
		close_child_semaphore(data);
		exit (1);
	}
	if (data->number_of_philo > 1)
		usleep((data->time_to_eat / 2 * 1000) * ((data->id + 1) % 2));
	while (1)
	{
		philo_routine(data);
		if (check_is_full(data))
			break ;
		if (check_is_dead(data))
			break ;
	}
	pthread_join(check, NULL);
	exit (0);
}

static void	philo_routine(t_data *data)
{
	sem_wait(data->forks);
	print_status_philo(data, "has taken a fork");
	sem_wait(data->forks);
	print_status_philo(data, "has taken a fork");
	print_status_philo(data, "is eating");
	sem_wait(data->sem_time_last_eat);
	data->time_last_eat = time_stamp();
	sem_post(data->sem_time_last_eat);
	accurate_usleep(data->time_to_eat);
	sem_post(data->forks);
	sem_post(data->forks);
	sem_wait(data->sem_number_times_eating);
	data->number_of_times_eating++;
	sem_post(data->sem_number_times_eating);
	print_status_philo(data, "is sleeping");
	accurate_usleep(data->time_to_sleep);
	print_status_philo(data, "is thinking");
}

void	close_child_semaphore(t_data *data)
{
	delete_sem_name_prefix(data, "last_eat_", &data->sem_time_last_eat);
	delete_sem_name_prefix(data, "n_eat_", &data->sem_number_times_eating);
	delete_sem_name_prefix(data, "is_dead_", &data->sem_is_dead);
	delete_sem_name_prefix(data, "is_full_", &data->sem_is_full);
}

static int	check_is_full(t_data *data)
{
	sem_wait(data->sem_is_full);
	if (data->is_full)
	{
		sem_post(data->sem_is_full);
		return (1);
	}
	sem_post(data->sem_is_full);
	return (0);
}

static int	check_is_dead(t_data *data)
{
	sem_wait(data->sem_is_dead);
	if (data->is_dead)
	{
		sem_post(data->sem_is_dead);
		return (1);
	}
	sem_post(data->sem_is_dead);
	return (0);
}
