/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:50:04 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/04 17:01:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	child_processes(t_data *data, pid_t *pids);
static void	kill_child_processes(pid_t *pids, int i);
static void	wait_child_processes(t_data *data, pid_t *pids);

int	launch_simulation(t_data *data)
{
	pid_t	*pids;

	pids = (pid_t *)malloc(sizeof(pid_t) * data->number_of_philo);
	if (!pids)
	{
		close_semaphore("print", &data->print);
		close_semaphore("forks", &data->forks);
		return (EXIT_FAILURE);
	}
	data->time_start = time_stamp();
	if (child_processes(data, pids))
		return (EXIT_FAILURE);
	wait_child_processes(data, pids);
	free(pids);
	return (EXIT_SUCCESS);
}

static int	child_processes(t_data *data, pid_t *pids)
{
	int		i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pids[i] = fork();
		if (pids[i] < 0)
		{
			kill_child_processes(pids, i - 1);
			error_fork(data, pids);
			return (EXIT_FAILURE);
		}
		if (pids[i] == 0)
		{
			data->id = i;
			data->time_last_eat = time_stamp();
			philo_processes(data);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	kill_child_processes(pid_t *pids, int i)
{
	while (i > -1)
	{
		kill(pids[i], SIGKILL);
		i--;
	}
}

static void	wait_child_processes(t_data *data, pid_t *pids)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WEXITSTATUS(status) == 1)
		{
			kill_child_processes(pids, data->number_of_philo - 1);
			break ;
		}
	}
}
