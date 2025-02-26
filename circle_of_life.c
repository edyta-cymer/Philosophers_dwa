/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_of_life.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:37:54 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/26 23:25:10 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		pick_forks(t_philo *philo)
{
	if(philo->data->num_of_philos == 1)
		return (-1);
	if(philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, "has taken a fork");
	}
	return (0);
}

int		ft_is_sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	return (0);
}

int		check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_stop);
	if(philo->data->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_stop);
		return(-1);
	}
	pthread_mutex_unlock(&philo->data->dead_stop);
	return (0);
}

int		ft_eat(t_philo *philo)
{
	if(pick_forks(philo) != 0)
		return(-1);
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	philo->eating_flag = 1;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating_flag = 0;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}