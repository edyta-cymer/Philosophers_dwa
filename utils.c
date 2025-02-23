/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:18 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/23 19:37:57 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	while (ft_isnum(str[i]) && str[i] != '\0')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (!ft_isnum(str[i]) && str[i] != '\0')
		return(-1);
	return (num * sign);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}