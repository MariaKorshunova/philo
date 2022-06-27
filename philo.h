/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:50:13 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/27 20:57:00 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>

# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_RESET	"\x1b[0m"

typedef struct s_philo
{
	int				id;
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
}	t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_must_eat;
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}	t_data;

/* parser.c */
int		parse_arguments(t_data *data, char **argv);

/* init.c */
int		init_simulation(t_data *data);

/* launch.c */
int		launch_simulation(t_data *data);

/* free_data.c */
void	free_all_data(t_data *data);

/* error.c */
void	error_arguments(void);
int		error_invalid_number_arguments(int argc);
void	error_function(char error);

#endif