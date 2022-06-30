/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:50:13 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/30 11:19:40 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_RESET	"\x1b[0m"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_must_eat;
	int				number_eating;
	int				alive;
	long			time_last_eat;
	long			*time_start;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_must_eat;
	long			time_start;
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_data;

/* parser.c */
int		parse_arguments(t_data *data, char **argv);

/* init.c */
int		init_simulation(t_data *data);

/* init_philo.c */
void	init_philo(t_data *data);

/* launch.c */
int		launch_simulation(t_data *data);

/* stop_simulation */
int		stop_simulation(t_data *data);

/* utils.c */
void	print_status_philo(t_philo *philo, char *action);
long	time_stamp(void);
void	accurate_usleep(int ms);

/* free_data.c */
void	free_all_data(t_data *data);

/* error.c */
void	error_arguments(void);
int		error_invalid_number_arguments(int argc);
void	error_description(char error);
void	error_mutex_fork_init(t_data *data, int index);

#endif