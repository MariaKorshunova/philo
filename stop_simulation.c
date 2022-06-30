/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:07:57 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/30 16:33:54 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_dying(t_data *data, int i);
static int	check_number_eating(t_data *data);

int	stop_simulation(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			pthread_mutex_lock(&(data->print));
			if (check_number_eating(data))
				return (1);
			if (check_dying(data, i))
				return (1);
			pthread_mutex_unlock(&(data->print));
			i++;
		}
	}
	return (0);
}

static int	check_number_eating(t_data *data)
{
	if (data->number_hungry_philo == 0)
	{
		printf("All philosophers are full.\n");
		return (1);
	}
	return (0);
}

static int	check_dying(t_data *data, int i)
{
	if ((time_stamp() - data->philo[i].time_last_eat) >= data->time_to_die)
	{
		pthread_mutex_unlock(&(data->print));
		data->philo[i].alive = 0;
		print_status_philo(&(data->philo[i]), "died");
		pthread_mutex_lock(&(data->print));
		return (1);
	}
	return (0);
}
