/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:25 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/26 23:21:28 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_life(void* arg)
{
	t_philo *philo;
	
	philo = (t_philo*)arg;
	if(philo->id % 2 == 0)
		ft_usleep(1);
	while(1)
	{
		if(ft_eat(philo) != 0)
			break;
		if(ft_is_sleeping(philo) != 0)
			break;
		print_message(philo, "is thinking");
	}
}

void	*check_monitor(void* arg)
{
	
}

int start_simulation(t_data *data, t_table *table)
{
	int		i;

	i = -1;
	data->started = get_time();
	while (++i < data->num_of_philos)
		if(pthread_create(&table->philos[i].thread, NULL, start_life, \
		&table->philos[i]) != 0)
			return(-1);
	if (pthread_create(&table->monitor, NULL, check_monitor, \ 
	&table->philos[0]) != 0)
		return (-1);
	while (--i >= 0)
		if (pthread_join(&table->philos[i].thread, NULL) != 0)
			return (-1);
	if (pthread_join(&table->monitor, NULL) != 0)
		return (-1);
	return (0);
}


int main(int argc, char *argv[])
{
	t_data data;
	t_table table;

	if (argc != 5 || argc != 6)
		return (0);
	if (init_data(&data, argv, argc) != 0)
		return (0);
	if (init_table(&data, &table) != 0)
		return (0);
	if (start_philos(&data, &table) != 0)
		return (0);
}

// next -> CREATE_THREADS 