/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:58:51 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/02 14:45:25 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_pars_arg(int argc, char **argv, t_all *all)
{
	if ((argc == 5 || argc == 6) && ft_is_numeric(argv, 0, 1))
	{
		all->arg_all.end = 0;
		all->arg_all.number_of_philosopher = ft_atoi(argv[1]);
		all->arg_all.time_to_die = ft_atoi(argv[2]);
		all->arg_all.time_to_eat = ft_atoi(argv[3]);
		all->arg_all.time_to_sleep = ft_atoi(argv[4]);
		all->arg_all.number_of_times_each_philosopher_must_eat = -1;
		if (argc == 6)
			all->arg_all.number_of_times_each_philosopher_must_eat
				= ft_atoi(argv[5]);
		if (all->arg_all.number_of_philosopher <= 0
			|| all->arg_all.time_to_die <= 0
			|| all->arg_all.time_to_eat <= 0 \
			|| all->arg_all.time_to_sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

int	ft_init(t_all *all)
{
	int	i;

	i = 0;
	pthread_mutex_init(&all->arg_all.write_mutex, NULL);
	pthread_mutex_init(&all->arg_all.dead, NULL);
	pthread_mutex_init(&all->arg_all.time_eat, NULL);
	pthread_mutex_init(&all->arg_all.finish, NULL);
	while (i < all->arg_all.number_of_philosopher)
	{
		all->philo[i].id = i + 1;
		all->philo[i].ms_eat = ft_time_current(all->arg_all.time_start);
		all->philo[i].nb_eat = 0;
		all->philo[i].finish = 0;
		all->philo[i].right_fork = NULL;
		pthread_mutex_init(&all->philo[i].left_fork, NULL);
		if (all->arg_all.number_of_philosopher == 1)
			return (1);
		if (i == all->arg_all.number_of_philosopher - 1)
			all->philo[i].right_fork = &all->philo[0].left_fork;
		else
			all->philo[i].right_fork = &all->philo[i + 1].left_fork;
		i++;
	}
	return (1);
}
