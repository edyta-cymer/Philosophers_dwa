/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <ecymer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:25 by ecymer            #+#    #+#             */
/*   Updated: 2025/02/23 19:51:14 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
    t_data data;
    t_table table;
    
    if(argc != 5 || argc != 6)
        return (0);   
    if(init_data(&data, argv, argc) != 0)
        return (0);
    if(init_table(&data, &table) != 0)
        return (0);
}

// next -> CREATE_THREADS 