/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:47:19 by jmabel            #+#    #+#             */
/*   Updated: 2022/06/29 16:43:28 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (error_invalid_number_arguments(argc))
		return (EXIT_FAILURE);
	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		error_description('m');
		return (EXIT_FAILURE);
	}
	if (parse_arguments(data, argv))
		return (EXIT_FAILURE);
	if (init_simulation(data))
		return (EXIT_FAILURE);
	if (launch_simulation(data))
		return (EXIT_FAILURE);
	free_all_data(data);
	return (EXIT_SUCCESS);
}
