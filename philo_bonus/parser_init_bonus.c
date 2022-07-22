/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:57:28 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/04 15:46:47 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	atoi_arguments(t_data *data, char **argv);
static int	ft_atoi_check_not_negative(const char *str);
static int	ft_create_nb(const char *str, int *i, long long *nb);

int	parse_arguments(t_data *data, char **argv)
{
	if (atoi_arguments(data, argv))
	{
		error_arguments();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_simulation(t_data *data)
{
	data->number_of_times_eating = 0;
	data->is_dead = 0;
	data->is_full = 0;
	data->id = -1;
	if (create_semaphore("print", &data->print, 1))
		return (EXIT_FAILURE);
	if (create_semaphore("forks", &data->forks, data->number_of_philo))
	{
		close_semaphore("print", &data->print);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	atoi_arguments(t_data *data, char **argv)
{
	data->number_of_philo = ft_atoi_check_not_negative(argv[1]);
	data->time_to_die = ft_atoi_check_not_negative(argv[2]);
	data->time_to_eat = ft_atoi_check_not_negative(argv[3]);
	data->time_to_sleep = ft_atoi_check_not_negative(argv[4]);
	if (data->number_of_philo <= 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0)
		return (EXIT_FAILURE);
	if (argv[5])
	{
		data->number_of_times_must_eat = ft_atoi_check_not_negative(argv[5]);
		if (data->number_of_times_must_eat <= 0)
			return (EXIT_FAILURE);
	}
	if (!argv[5])
		data->number_of_times_must_eat = -1;
	return (EXIT_SUCCESS);
}

static int	ft_atoi_check_not_negative(const char *str)
{
	int				i;
	int				minus;
	long long		nb;
	size_t			nb_digit;

	i = 0;
	nb = 0;
	nb_digit = 0;
	minus = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		minus = -1;
	}
	if (str[i] == '\0')
		return (-1);
	nb_digit = ft_create_nb(str, &i, &nb);
	if (str[i] != '\0' || nb > 2147483647
		|| (minus == -1 && nb != 0) || nb_digit > 11)
		return (-1);
	return (nb);
}

static	int	ft_create_nb(const char *str, int *i, long long *nb)
{
	size_t			nb_digit;

	nb_digit = 0;
	while (str[*i] == '0')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*nb = 10 * (*nb) + str[(*i)++] - '0';
		nb_digit++;
	}
	return (nb_digit);
}
