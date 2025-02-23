/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:33 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/23 21:39:30 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_data(t_data *data, char *argv[], int argc)
{
	int		i;

	i = 0;
	while (argv[++i])
		if(ft_atol(argv[i]) <= 0)
			return(-1);
	if(ft_atol(argv[1]) > MAX_PHILOSOPHERS)
		return(-2);
	data->num_of_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if(argc == 6)
		data->amount_meals = ft_atol(argv[5]);
	else
		data->amount_meals = 0;
	data->dead_flag = 0;
	if(pthread_mutex_init(&data->dead_stop, NULL) != 0)
		return(-1);
	if(pthread_mutex_init(&data->write_lock, NULL) != 0)
		return(pthread_mutex_destroy(&data->dead_stop), -1);
	return (0);
}

int		init_table(t_data *data, t_table *table)
{
	int i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if(!table->forks)
		return (-1);
	table->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if(!table->philos)
		return (free(table->forks), -1);
	while(i < data->num_of_philos)
	{
		if(pthread_mutex_init(&table->forks[i], NULL) != 0)
			return(free_mutex(i, table), 2);
		i++;	
	}
	//table->monitor =
	return (0);
}
