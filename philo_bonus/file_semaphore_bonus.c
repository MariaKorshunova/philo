/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_semaphore_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:48:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/04 14:48:32 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char		*ft_strjoin(char const *s1, char const *s2);
static char	*ft_itoa(int nb);
static	int	ft_intlen(long n);
static	char	*ft_itoa_record(long n, int len, char *str);

char	*create_file_name(char *prefix, int id)
{
	char	*id_str;
	char	*name;

	id_str = ft_itoa(id);
	if (id_str == NULL)
		return (NULL);
	name = ft_strjoin(prefix, id_str);
	if (!name)
	{
		free(id_str);
		return (NULL);
	}
	free(id_str);
	return (name);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (i < ft_strlen(s2))
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

static char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		len;

	n = nb;
	len = ft_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_itoa_record(n, len, str);
	return (str);
}

static	int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	return (len + 1);
}

static	char	*ft_itoa_record(long n, int len, char *str)
{
	int	finish;
	int	i;

	finish = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		finish = 1;
	}
	i = len - 1;
	while (i >= finish)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}
