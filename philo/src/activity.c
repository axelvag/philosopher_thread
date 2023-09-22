/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:00:14 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/09 12:21:41 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_take_fork(t_philo *philo)
{
	if (philo->id == philo->arg->number_of_philosopher)
		pthread_mutex_lock((philo->right_fork));
	else
		pthread_mutex_lock(&(philo->left_fork));
	pthread_mutex_lock(&(philo->arg->write_mutex));
	ft_write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&(philo->arg->write_mutex));
	if (philo->arg->number_of_philosopher == 1)
	{
		ft_usleep(philo->ms_eat * 2);
		return ;
	}
	if (philo->id == philo->arg->number_of_philosopher)
		pthread_mutex_lock(&(philo->left_fork));
	else
		pthread_mutex_lock((philo->right_fork));
	pthread_mutex_lock(&(philo->arg->write_mutex));
	ft_write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&(philo->arg->write_mutex));
}

void	ft_sleep_die(t_philo *philo)
{
	ft_usleep(philo->arg->time_to_die + 1);
	pthread_mutex_lock(&philo->arg->write_mutex);
	ft_write_status("is dead\n", philo);
	pthread_mutex_unlock(&philo->arg->write_mutex);
	pthread_mutex_lock(&philo->arg->dead);
	philo->arg->end = 1;
	pthread_mutex_unlock(&philo->arg->dead);
}

void	ft_sleep(t_philo *philo)
{
	if (philo->arg->time_to_die < philo->arg->time_to_sleep)
	{
		ft_sleep_die(philo);
		return ;
	}
	pthread_mutex_lock(&philo->arg->write_mutex);
	ft_write_status("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->arg->write_mutex);
	if (philo->arg->time_to_die < philo->arg->time_to_eat
		+ philo->arg->time_to_sleep || (philo->arg->number_of_philosopher
			% 2 != 0 && philo->arg->time_to_die < philo->arg->time_to_eat * 3)
		|| (philo->arg->number_of_philosopher
			% 2 == 0 && philo->arg->time_to_die < philo->arg->time_to_eat * 2))
	{
		ft_usleep(philo->arg->time_to_die - philo->arg->time_to_eat);
		pthread_mutex_lock(&philo->arg->write_mutex);
		ft_write_status("is dead\n", philo);
		pthread_mutex_unlock(&philo->arg->write_mutex);
		pthread_mutex_lock(&philo->arg->dead);
		philo->arg->end = 1;
		pthread_mutex_unlock(&philo->arg->dead);
	}
	usleep((philo->arg->time_to_sleep) * 1000);
}

void	ft_eat_end_unlock(t_philo *philo)
{
	if (philo->id == philo->arg->number_of_philosopher)
	{
		pthread_mutex_unlock((philo->right_fork));
		pthread_mutex_unlock(&(philo->left_fork));
	}
	else
	{
		pthread_mutex_unlock(&(philo->left_fork));
		pthread_mutex_unlock((philo->right_fork));
	}
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->write_mutex);
	ft_write_status("is eating\n", philo);
	pthread_mutex_unlock(&philo->arg->write_mutex);
	if ((philo->arg->time_to_die > philo->arg->time_to_eat
			&& philo->arg->time_to_die < philo->arg->time_to_sleep)
		|| (philo->arg->time_to_die < philo->arg->time_to_eat))
	{
		ft_usleep(philo->arg->time_to_die + 1);
		pthread_mutex_lock(&philo->arg->write_mutex);
		ft_write_status("is dead\n", philo);
		pthread_mutex_unlock(&philo->arg->write_mutex);
		pthread_mutex_lock(&philo->arg->dead);
		philo->arg->end = 1;
		pthread_mutex_unlock(&philo->arg->dead);
	}
	philo->ms_eat = ft_time_total();
	ft_usleep(philo->arg->time_to_eat);
	ft_eat_end_unlock(philo);
}
