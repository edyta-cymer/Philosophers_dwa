/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:33 by ecymer            #+#    #+#             */
/*   Updated: 2025/03/01 17:38:33 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	init_philo(t_data *data, t_table *table, int i)
{
	t_philo		philo;

	philo.id = i + 1;
	philo.meals_eaten = 0;
	philo.last_meal = get_time();
	philo.eating_flag = 0;
	philo.data = data;
	philo.table = table;
	philo.r_fork = &table->forks[i];
	if (i == 0)
		philo.l_fork = &table->forks[data->num_of_philos - 1];
	else
		philo.l_fork = &table->forks[i - 1];
	pthread_mutex_init(&philo.meal_lock, NULL);
	return (philo);
}

int	init_data(t_data *data, char *argv[], int argc)
{
	int		i;

	i = 0;
	while (argv[++i])
		if (ft_atol(argv[i]) <= 0)
			return (-1);
	if (ft_atol(argv[1]) > MAX_PHILOSOPHERS)
		return (-2);
	data->num_of_philos = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		data->amount_meals = ft_atol(argv[5]);
	else
		data->amount_meals = 0;
	data->dead_flag = 0;
	if (pthread_mutex_init(&data->dead_stop, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (pthread_mutex_destroy(&data->dead_stop), -1);
	return (0);
}

int	init_table(t_data *data, t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!table->forks)
		return (-1);
	table->philos = malloc(sizeof(t_philo) * data->num_of_philos);
	if (!table->philos)
		return (free(table->forks), -1);
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (free_mutex(i, table), 2);
		i++;
	}
	i = 0;
	while (i < data->num_of_philos)
		table->philos[i] = init_philo(data, table, i++);
	return (0);
}
