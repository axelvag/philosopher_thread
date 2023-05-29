/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:26:38 by avaganay          #+#    #+#             */
/*   Updated: 2023/05/18 15:52:52 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_arg
{
	int	number_of_philosopher;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_arg;

typedef struct s_philo
{
	int		id;
}	t_philo;

typedef struct s_all
{
	t_philo	*philo;
	t_arg	arg;
}	t_all;

int	ft_strlen(const char *str);
int	ft_atoi(const char *str);
int	ft_is_numeric(char **argv, int i, int j);

#endif