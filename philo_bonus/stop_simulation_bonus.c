/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:50:17 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/04 17:20:51 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_dying(t_data *data);
static int	check_eaten(t_data *data);

void	*stop_simulation(void *argv)
{
	t_data	*data;

	data = argv;
	while (1)
	{
		if (check_dying(data))
			break ;
		if (check_eaten(data))
			break ;
	}
	close_child_semaphore(data);
	if (data->is_dead)
		exit (1);
	else
		exit (0);
}

static int	check_dying(t_data *data)
{
	sem_wait(data->sem_time_last_eat);
	if (time_stamp() - data->time_last_eat > data->time_to_die)
	{
		sem_wait(data->sem_is_dead);
		data->is_dead = 1;
		sem_post(data->sem_is_dead);
		sem_wait(data->print);
		printf("%ld %d %s\n", time_stamp() - data->time_start, data->id,
			"is dead");
		sem_post(data->print);
		return (1);
	}
	sem_post(data->sem_time_last_eat);
	return (0);
}

static int	check_eaten(t_data *data)
{
	sem_wait(data->sem_number_times_eating);
	if (data->number_of_times_must_eat != -1
		&& data->number_of_times_eating == data->number_of_times_must_eat)
	{
		sem_wait(data->sem_is_full);
		data->is_full = 1;
		sem_post(data->sem_is_full);
		return (1);
	}
	sem_post(data->sem_number_times_eating);
	return (0);
}
