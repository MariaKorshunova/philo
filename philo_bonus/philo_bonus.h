/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:29:50 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/04 15:45:59 by jmabel           ###   ########.fr       */
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
# include <signal.h>

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
	int			is_dead;
	int			is_full;
	long		time_start;
	long		time_last_eat;
	sem_t		*print;
	sem_t		*forks;
	sem_t		*sem_time_last_eat;
	sem_t		*sem_number_times_eating;
	sem_t		*sem_is_dead;
	sem_t		*sem_is_full;
}	t_data;

/* parser_init_bonus.c */
int		parse_arguments(t_data *data, char **argv);
int		init_simulation(t_data *data);

/* launch_bonus.c */
int		launch_simulation(t_data *data);

/* philo_processes_bonus.c */
int		philo_processes(t_data *data);
void	close_child_semaphore(t_data *data);

/* stop_simulation_bonus.c */
void	*stop_simulation(void *argv);

/* semaphore.c */
int		create_semaphore(char *name, sem_t **semaphore, int value);
void	close_semaphore(char *name, sem_t **semaphore);
int		child_create_semaphore(t_data *data);
int		delete_sem_name_prefix(t_data *data, char *prefix, sem_t **sem);

/* file_semaphore.c */
char	*create_file_name(char *prefix, int id);

/* utils_bonus.c */
long	time_stamp(void);
void	accurate_usleep(int ms);
void	print_status_philo(t_data *data, char *action);
size_t	ft_strlen(const char *s);

/* error_bonus.h */
int		error_invalid_number_arguments(int argc);
void	error_description(char error);
void	error_arguments(void);
void	error_fork(t_data *data, pid_t *pids);

#endif