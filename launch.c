/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:13:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/23 17:45:32 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void)
{
	printf("Thread has created");
}

int	launch_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_create(&data->threads[i], NULL, (void *)&routine, NULL))
		{
			// print error
			// free memory
			return (EXIT_FAILURE);
		}
		pthread_detach(data->threads[0]);
		i++;
	}
	return (EXIT_SUCCESS);
}
