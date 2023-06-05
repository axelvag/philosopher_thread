/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:19:00 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/05 09:28:23 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork));
	ft_write_status(" has taken a fork\n", philo);
	if (philo->arg->number_of_philosopher == 1)
	{
		ft_usleep(philo->ms_eat * 2);
		return ;
	}
	pthread_mutex_lock((philo->right_fork));
	ft_write_status(" has taken a fork\n", philo);
}

void	ft_all_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->finish);
	philo->finish = 1;
	philo->arg->nb_p_finish++;
	if (philo->arg->nb_p_finish == philo->arg->number_of_philosopher)
	{
		pthread_mutex_unlock(&philo->arg->finish);
		ft_is_dead(philo, 2);
	}
	pthread_mutex_unlock(&philo->arg->finish);
}

void	*ft_routine(void *data)
{
	t_philo	*philo;
	// int		i;

	philo = (t_philo *)data;
	if (philo->id % 2 != 0)
		usleep(philo->arg->time_to_eat / 10);
	// i = 0;
	// while (i++ < 10)
	// 	printf("Philo %d: %d\n", philo->id, i);
	while (!ft_is_dead(philo, 0))
	{
		// ft_write_status("is thinking\n", philo);
		ft_take_fork(philo);
		if ((ft_time_total() - philo->ms_eat)
			>= (long)(philo->arg->time_to_die))
		{
			ft_all_philo_eat(philo);
			ft_write_status("is dead\n", philo);
			return (NULL);
		}
		if ((int)++philo->nb_eat
			== philo->arg->number_of_times_each_philosopher_must_eat)
		{
			ft_all_philo_eat(philo);
			ft_write_status("is dead\n", philo);
			return (NULL);
		}
	}
	return (NULL);
}
