/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:58:53 by avaganay          #+#    #+#             */
/*   Updated: 2023/05/30 13:59:07 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_time_current(struct timeval *time_start)
{
	struct timeval	time_current;

	gettimeofday(&time_current, NULL);
	return (((time_current.tv_sec - time_start->tv_sec) * 1000)
		+ ((time_current.tv_usec - time_start->tv_usec) / 1000));
}
