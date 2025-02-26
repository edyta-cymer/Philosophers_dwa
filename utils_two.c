/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:22:12 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/26 22:24:26 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void     free_mutex(int i, t_table *table)
{
    while( --i >= 0)
        pthread_mutex_destroy(&table->forks[i]);
    
}

void    print_message(t_philo *philo, char *str)
{
    size_t current_time;

    current_time = get_time() - philo->data->started;
    pthread_mutex_lock(&philo->data->write_lock);
    printf("%lu %d %s\n", current_time, philo->id, str);
    pthread_mutex_unlock(&philo->data->write_lock);
}


//  timestamp_in_ms X has taken a fork
//◦ timestamp_in_ms X is eating
//◦ timestamp_in_ms X is sleeping
//◦ timestamp_in_ms X is thinking
//◦ timestamp_in_ms X died