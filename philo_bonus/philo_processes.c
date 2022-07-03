/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:38:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/03 22:07:47 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_routine(t_data *data);

int	philo_processes(t_data *data)
{
	if (child_create_semaphore(data))
		exit (1);
	if (data->number_of_philo > 1)
		usleep((data->time_to_eat / 2 * 1000) * ((data->id + 1) % 2));
	while (1)
	{
		philo_routine(data);
	}
	exit (0);
}

static void	philo_routine(t_data *data)
{
	sem_wait(data->forks);
	print_status_philo(data, "has taken a fork");
	sem_wait(data->forks);
	print_status_philo(data, "has taken a fork");
	print_status_philo(data, "is eating");
}
