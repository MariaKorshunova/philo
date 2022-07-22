/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:19:00 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/04 15:48:19 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	create_sem_name_prefix(t_data *data, char *prefix, sem_t **sem);

int	create_semaphore(char *name, sem_t **semaphore, int value)
{
	sem_unlink(name);
	*semaphore = sem_open(name, O_CREAT, 0644, value);
	if (*semaphore == ((sem_t *)-1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	close_semaphore(char *name, sem_t **semaphore)
{
	sem_close(*semaphore);
	sem_unlink(name);
}

int	child_create_semaphore(t_data *data)
{
	if (create_sem_name_prefix(data, "last_eat_", &data->sem_time_last_eat))
		return (EXIT_FAILURE);
	if (create_sem_name_prefix(data, "n_eat_", &data->sem_number_times_eating))
	{
		delete_sem_name_prefix(data, "last_eat_", &data->sem_time_last_eat);
		return (EXIT_FAILURE);
	}
	if (create_sem_name_prefix(data, "is_dead_", &data->sem_is_dead))
	{
		delete_sem_name_prefix(data, "last_eat_", &data->sem_time_last_eat);
		delete_sem_name_prefix(data, "n_eat_", &data->sem_number_times_eating);
		return (EXIT_FAILURE);
	}
	if (create_sem_name_prefix(data, "is_full_", &data->sem_is_full))
	{
		delete_sem_name_prefix(data, "last_eat_", &data->sem_time_last_eat);
		delete_sem_name_prefix(data, "n_eat_", &data->sem_number_times_eating);
		delete_sem_name_prefix(data, "is_dead_", &data->sem_is_dead);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	create_sem_name_prefix(t_data *data, char *prefix, sem_t **sem)
{
	char	*name;

	name = create_file_name(prefix, data->id);
	if (!name)
		return (EXIT_FAILURE);
	if (create_semaphore(name, sem, 1))
	{
		free(name);
		return (EXIT_FAILURE);
	}
	free(name);
	return (EXIT_SUCCESS);
}

int	delete_sem_name_prefix(t_data *data, char *prefix, sem_t **sem)
{
	char	*name;

	name = create_file_name(prefix, data->id);
	if (!name)
		return (EXIT_FAILURE);
	close_semaphore(name, sem);
	free(name);
	return (EXIT_SUCCESS);
}
