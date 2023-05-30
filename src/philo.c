/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:43:22 by avaganay          #+#    #+#             */
/*   Updated: 2023/05/30 15:07:16 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// int	main(int argc, char **argv)
// {
// 	t_all	all;

// 	if (!(ft_pars_arg(argc, argv, &all)))
// 		return (ft_exit("Invalid Arguments\n"));
// 	gettimeofday(all.time_start, NULL);
// 	all.philo = malloc(sizeof(t_philo) * all.arg_all.number_of_philosopher);
// 	if (!all.philo)
// 		return (ft_exit("Malloc\n"));
// 	all.end = 0;
// 	all.nb_philo_finish = 0;
// 	if (ft_init(&all) == 0)
// 		return (free(all.philo), 0);
// 	return (0);
// }

int	main(void)
{
	t_all	all;

	all.time_start = NULL;
	gettimeofday(all.time_start, NULL);
	printf("%d\n", ft_time_current(all.time_start));
	return (0);
}
