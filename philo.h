/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:59:31 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/23 21:11:04 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf
#include <unistd.h> // write, usleep
#include <stdbool.h>
#include <pthread.h>
#include <sys/time.h> // gettimeofday
#include <limits.h> // INT_MAX
#include <errno.h>

#define MAX_PHILOSOPHERS 200

typedef struct s_data
{
	int num_of_philos;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t started;
	int amount_meals;
	pthread_mutex_t dead_stop;
	pthread_mutex_t write_lock;
	int dead_flag;
} t_data;

struct s_philo;

typedef struct s_table
{
	pthread_mutex_t *forks;
	struct s_philo *philos;
	pthread_t monitor;
} t_table;

typedef struct s_philo
{
	pthread_t thread;
	int id;
	int meals_eaten;
	size_t last_meal;
	int eating_flag;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	pthread_mutex_t meal_lock;
	struct s_data *data;
	struct s_table *table;
} t_philo;


int				init_data(t_data *data, char *argv[], int argc);
long			ft_atol(const char *str);
