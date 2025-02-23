/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecymer <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:16 by ecymer            #+#    #+#             */
/*   Updated: 2024/12/29 23:33:27 by ecymer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    is_valid_num(const char *arg)
{
    int     i;

    i = 0;
    while(arg[i] != '\0')
    {
        if(ft_isnum(arg[i]) == 0)
            return(false);
        i++;
    }
    return (true);
}

bool    validate_optional_input(const char *arg)
{
    if (!is_valid_num(arg))
        error_exit("Error: Argument 5 contains invalid characters.\n");
    if (ft_atoi(arg) < 0)
        error_exit("Error: Argument 5 must be a non-negative number.\n");
    return(true);
}

bool    validate_input(char *argv[])
{
    int     i;
    int     j;

    i = 1;
    while(i <= 4)
    {
        j = 0;
        while(argv[i][j])
        {
            if(ft_isnum(argv[i][j]) == 0)
                error_exit("Error: Argument contains invalid characters.\n");
            j++;
        }
        if (ft_atoi(argv[i]) <= 0)
            error_exit("Error: Argument must be a positive number.\n");
        i++;
    }
    if (argv[5]) {
        validate_optional_input(argv[5]);
    }
    if(ft_atoi(argv[1]) > MAX_PHILOSOPHERS)
        error_exit("Error: Too many philosophers...");
        
    return(true);
}