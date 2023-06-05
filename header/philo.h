/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:26:38 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/05 09:22:16 by avaganay         ###   ########.fr       */
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
	struct timeval	time_start;
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				end;
	int				nb_p_finish;
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
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	pthread_t		thread_id;
	pthread_t		thread_death_id;
}	t_philo;

typedef struct s_all
{
	t_philo			*philo;
	t_arg			arg_all;
	int				nb_philo_finish;
	int				end;
}	t_all;

/**********************************ROUTINE**********************************/

int			ft_thread(t_all *all);
void		*ft_routine(void *data);

/**********************************UTILS**********************************/

int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
int			ft_is_numeric(char **argv, int i, int j);
int			ft_exit(char *str);
long int	ft_time_current(struct timeval time_start);
long int	ft_time_total(void);
int			ft_is_dead(t_philo *philo, int i);
void		ft_write_status(char *str, t_philo *philo);
void		ft_usleep(long int time_in_ms);

/**********************************INIT**********************************/

int			ft_init(t_all *all);
int			ft_pars_arg(int argc, char **argv, t_all *all);

#endif