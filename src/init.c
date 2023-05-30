/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:58:51 by avaganay          #+#    #+#             */
/*   Updated: 2023/05/30 14:01:57 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_pars_arg(int argc, char **argv, t_all *all)
{
	if ((argc == 5 || argc == 6) && ft_is_numeric(argv, 0, 1))
	{
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