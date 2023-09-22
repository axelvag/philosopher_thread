/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:19:00 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/09 12:20:33 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->write_mutex);
	ft_write_status("is thinking\n", philo);
	pthread_mutex_unlock(&philo->arg->write_mutex);
}

void	ft_write_status(char *str, t_philo *philo)
{
	long int		time;

	time = -1;
	time = ft_time_current(philo->arg->time_start);
	pthread_mutex_lock(&philo->arg->dead);
	if (philo->arg->end == 1)
	{
		pthread_mutex_unlock(&philo->arg->dead);
		return ;
	}
	pthread_mutex_unlock(&philo->arg->dead);
	if (time >= 0 && time <= 2147483647 && !ft_is_dead(philo, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
	}
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

int	ft_start_verif_routine(t_philo	*philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(philo->arg->time_to_eat / 10);
	if (philo->arg->number_of_philosopher == 1)
	{
		pthread_mutex_lock(&(philo->arg->write_mutex));
		ft_write_status("has taken a fork\n", philo);
		ft_usleep(philo->arg->time_to_die);
		ft_write_status("is dead\n", philo);
		pthread_mutex_unlock(&(philo->arg->write_mutex));
		return (1);
	}
	return (0);
}

void	*ft_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (ft_start_verif_routine(philo))
		return (NULL);
	while (!ft_is_dead(philo, 0) && philo->finish == 0)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		if ((ft_time_total() - philo->ms_eat > philo->arg->time_to_die)
			>= (long)(philo->arg->time_to_die))
		{
			ft_all_philo_eat(philo);
			ft_write_status("is dead\n", philo);
			return (NULL);
		}
		if ((int)++philo->nb_eat
			== philo->arg->number_of_times_each_philosopher_must_eat)
			return (ft_all_philo_eat(philo), NULL);
	}
	return (NULL);
}
