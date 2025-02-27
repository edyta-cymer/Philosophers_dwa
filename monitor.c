/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:32:28 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/27 16:55:45 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	amount_meals(t_philo *philo)
{
	int		full_tummy_philo;
	int		i;
	
	full_tummy_philo = 0;
	i = -1;
	if (philo->data->amount_meals == 0)
		return (0);
	while (++i < philo->data->num_of_philos)
	{
		pthread_mutex_lock(&philo[i].meal_lock);
		if(philo->meals_eaten >= philo->data->amount_meals)
			full_tummy_philo++;
		pthread_mutex_unlock(&philo[i].meal_lock);
	}
	if(full_tummy_philo == philo->data->num_of_philos)
	{
		pthread_mutex_lock(&philo->data->dead_stop);
		philo->data->dead_flag = 1;
		pthread_mutex_unlock(&philo->data->dead_stop);
		return (-1);
	}
	return (0);
}
