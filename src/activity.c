/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:00:14 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/02 15:00:58 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// void	write_status(char *str, t_philo *philo)
// {
// 	long int		time;

// 	time = -1;
// 	time = ft_time_current(philo->arg->time_start);
// 	usleep(200 * 1000);
// 	if (time >= 0 && time <= 2147483647 && !ft_is_dead(philo, 0))
// 	{
// 		printf("%ld ", time);
// 		printf("Philo %d %s", philo->id, str);
// 	}
// }

// long int	actual_time(void)
// {
// 	long int			time;
// 	struct timeval		current_time;

// 	time = 0;
// 	if (gettimeofday(&current_time, NULL) == -1)
// 		ft_exit("Gettimeofday returned -1\n");
// 	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
// 	return (time);
// }

// void	sleep_think(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->arg->write_mutex);
// 	write_status("is sleeping\n", philo);
// 	pthread_mutex_unlock(&philo->arg->write_mutex);
// 	usleep(philo->arg->time_to_sleep);
// 	pthread_mutex_lock(&philo->arg->write_mutex);
// 	write_status("is thinking\n", philo);
// 	pthread_mutex_unlock(&philo->arg->write_mutex);
// }

// void	activity(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->left_fork);
// 	pthread_mutex_lock(&philo->arg->write_mutex);
// 	write_status("has taken a fork\n", philo);
// 	pthread_mutex_unlock(&philo->arg->write_mutex);
// 	if (!philo->right_fork)
// 	{
// 		usleep(philo->arg->time_to_die * 2);
// 		return ;
// 	}
// 	pthread_mutex_lock(philo->right_fork);
// 	pthread_mutex_lock(&philo->arg->write_mutex);
// 	write_status("has taken a fork\n", philo);
// 	pthread_mutex_unlock(&philo->arg->write_mutex);
// 	pthread_mutex_lock(&philo->arg->write_mutex);
// 	write_status("is eating\n", philo);
// 	pthread_mutex_lock(&philo->arg->time_eat);
// 	philo->ms_eat = actual_time();
// 	pthread_mutex_unlock(&philo->arg->time_eat);
// 	pthread_mutex_unlock(&philo->arg->write_mutex);
// 	usleep(philo->arg->time_to_eat);
// 	pthread_mutex_unlock(philo->right_fork);
// 	pthread_mutex_unlock(&philo->left_fork);
// 	sleep_think(philo);
// }

// void	*is_dead(void	*data)
// {
// 	t_philo					*philo;

// 	philo = (t_philo *)data;
// 	usleep(philo->arg->time_to_die + 1);
// 	pthread_mutex_lock(&philo->arg->time_eat);
// 	pthread_mutex_lock(&philo->arg->finish);
// 	if (!ft_is_dead(philo, 0) && !philo->finish
// 		&& ((actual_time() - philo->ms_eat)
// 			>= (long)(philo->arg->time_to_die)))
// 	{
// 		pthread_mutex_unlock(&philo->arg->time_eat);
// 		pthread_mutex_unlock(&philo->arg->finish);
// 		pthread_mutex_lock(&philo->arg->write_mutex);
// 		write_status("died\n", philo);
// 		pthread_mutex_unlock(&philo->arg->write_mutex);
// 		ft_is_dead(philo, 1);
// 	}
// 	pthread_mutex_unlock(&philo->arg->time_eat);
// 	pthread_mutex_unlock(&philo->arg->finish);
// 	return (NULL);
// }

// void	*ft_routine(void *data)
// {
// 	t_philo	*philo;
// 	// int		i;

// 	philo = (t_philo *)data;
// 	if (philo->id % 2 != 0)
// 		usleep(philo->arg->time_to_eat / 10);
// 	// i = 0;
// 	// while (i++ < 10)
// 	// 	printf("Philo %d: %d\n", philo->id, i);
// 	while (!ft_is_dead(philo, 0))
// 	{
// 		pthread_create(&philo->thread_death_id, NULL, is_dead, data);
// 		activity(philo);
// 		pthread_detach(philo->thread_death_id);
// 		if ((int)++philo->nb_eat
// 			== philo->arg->number_of_times_each_philosopher_must_eat)
// 		{
// 			pthread_mutex_lock(&philo->arg->finish);
// 			philo->finish = 1;
// 			philo->arg->nb_p_finish++;
// 			if (philo->arg->nb_p_finish == philo->arg->number_of_philosopher)
// 			{
// 				pthread_mutex_unlock(&philo->arg->finish);
// 				ft_is_dead(philo, 2);
// 			}
// 			pthread_mutex_unlock(&philo->arg->finish);
// 			return (NULL);
// 		}
// 	}
// 	return (NULL);
// }