/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:47:15 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/30 17:06:26 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status_philo(t_philo *philo, char *action)
{
	pthread_mutex_lock(&(philo->data->print));
	printf("%ld %d %s\n",
		time_stamp() - philo->data->time_start, philo->id, action);
	pthread_mutex_unlock(&(philo->data->print));
}

long	time_stamp(void)
{
	struct timeval	moment;

	gettimeofday(&moment, NULL);
	return (moment.tv_sec * 1000 + moment.tv_usec / 1000);
}

void	accurate_usleep(int ms)
{
	long	current_time;

	current_time = time_stamp();
	usleep(ms * 920);
	while (time_stamp() < current_time + (long)ms)
		usleep(100);
}

void	free_all_data(t_data *data)
{
	free(data->forks);
	free(data->threads);
	free(data->philo);
	free(data);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_unlock(&data->forks[i]);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	// pthread_mutex_unlock(&(data->print));
	pthread_mutex_destroy(&(data->print));
}
