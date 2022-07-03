/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:19:00 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/03 22:13:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	create_semaphore(char *name, sem_t **semaphore, int value)
{
	sem_unlink(name);
	*semaphore = sem_open(name, O_CREAT, 0644, value);
	if (*semaphore == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	close_semaphore(char *name, sem_t **semaphore)
{
	sem_close(*semaphore);
	sem_unlink(name);
}

int	child_create_semaphore(t_data *data)
{
	char	*name[50];

	create_file_name(name, "sem_time_last_eat_", data->id);
}
