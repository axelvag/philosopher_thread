/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:26:38 by avaganay          #+#    #+#             */
/*   Updated: 2023/05/30 14:46:57 by avaganay         ###   ########.fr       */
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
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;
}	t_arg;

typedef struct s_philo
{
	int				id;
	t_arg			*arg;
	long int		ms_eat;
	unsigned int	nb_eat;
	int				finish;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	l_f;
}	t_philo;

typedef struct s_all
{
	t_philo			*philo;
	t_arg			arg_all;
	struct timeval	*time_start;
	int				nb_philo_finish;
	int				end;
}	t_all;

/**********************************UTILS**********************************/

int	ft_strlen(const char *str);
int	ft_atoi(const char *str);
int	ft_is_numeric(char **argv, int i, int j);
int	ft_exit(char *str);
int	ft_time_current(struct timeval *time_start);

/**********************************INIT**********************************/

int	ft_init(t_all *all);
int	ft_pars_arg(int argc, char **argv, t_all *all);

#endif