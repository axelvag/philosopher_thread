/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:58:53 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/02 15:22:51 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

long int	ft_time_total(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

long int	ft_time_current(struct timeval time_start)
{
	struct timeval	time_current;

	gettimeofday(&time_current, NULL);
	return (((time_current.tv_sec - time_start.tv_sec) * 1000)
		+ ((time_current.tv_usec - time_start.tv_usec) / 1000));
}

int	ft_is_dead(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->arg->dead);
	if (i)
		philo->arg->end = i;
	if (philo->arg->end)
	{
		pthread_mutex_unlock(&philo->arg->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->arg->dead);
	return (0);
}
