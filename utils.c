/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:47:15 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/29 20:51:37 by jmabel           ###   ########.fr       */
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
