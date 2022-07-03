/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:29:50 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/03 22:06:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_RESET	"\x1b[0m"

typedef struct s_data
{
	int			id;
	int			number_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_must_eat;
	int			number_of_times_eating;
	long		time_start;
	long		time_last_eat;
	sem_t		*print;
	sem_t		*forks;
	sem_t		*sem_time_last_eat;
}	t_data;

/* parser_init_bonus.c */
int		parse_arguments(t_data *data, char **argv);
int		init_simulation(t_data *data);

/* launch_bonus.c */
int		launch_simulation(t_data *data);

/* philo_processes.c */
int		philo_processes(t_data *data);

/* semaphore.c */
int		create_semaphore(char *name, sem_t **semaphore, int value);
int		close_semaphore(char *name, sem_t **semaphore);

/* utils_bonus.c */
long	time_stamp(void);
void	accurate_usleep(int ms);
void	print_status_philo(t_data *data, char *action);

/* error_bonus.h */
int		error_invalid_number_arguments(int argc);
void	error_description(char error);
void	error_arguments(void);
void	error_fork(t_data *data, pid_t *pids);

#endif