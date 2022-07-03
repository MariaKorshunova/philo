/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:47:15 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/03 22:17:03 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	print_status_philo(t_data *data, char *action)
{
	sem_wait(data->print);
	printf("%ld %d %s\n", time_stamp() - data->time_start, data->id, action);
	sem_post(data->print);
}

void	create_file_name(char name[], char *prefix, int id)
{
	int	i;

	i = 0;
	while (prefix[i])
	{
		name[i] = prefix[i];
		i++;
	}
	
}