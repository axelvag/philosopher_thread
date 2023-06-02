/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:43:22 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/02 15:33:32 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

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
		
		if ((ft_time_total() - philo->ms_eat)
			>= (long)(philo->arg->time_to_die))
		{
			ft_all_philo_eat(philo);
			return (NULL);
		}
		if ((int)++philo->nb_eat
			== philo->arg->number_of_times_each_philosopher_must_eat)
		{
			ft_all_philo_eat(philo);
			return (NULL);
		}
	}
	return (NULL);
}

int	ft_thread(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arg_all.number_of_philosopher)
	{
		all->philo[i].arg = &all->arg_all;
		if (pthread_create(&all->philo[i].thread_id, NULL, ft_routine,
				&all->philo[i]) != 0)
			return (ft_exit("Error: pthread_create\n"));
		pthread_join(all->philo[i].thread_id, NULL);
		usleep(50);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (!(ft_pars_arg(argc, argv, &all)))
		return (ft_exit("Invalid Arguments\n"));
	gettimeofday(&all.arg_all.time_start, NULL);
	all.philo = malloc(sizeof(t_philo) * all.arg_all.number_of_philosopher);
	if (!all.philo)
		return (ft_exit("Malloc\n"));
	all.end = 0;
	all.nb_philo_finish = 0;
	if (ft_init(&all) == 0 || ft_thread(&all))
		return (free(all.philo), 0);
	return (0);
}

// int	main(void)
// {
// 	t_all	all;

// 	gettimeofday(&all.time_start, NULL);
// 	printf("%d\n", ft_time_current(all.time_start));
// 	return (0);
// }
