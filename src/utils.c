/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:59:18 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/02 15:36:57 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_write_status(char *str, t_philo *philo)
{
	long int		time;

	time = -1;
	time = ft_time_current(philo->arg->time_start);
	usleep(200 * 1000);
	if (time >= 0 && time <= 2147483647 && !ft_is_dead(philo, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
}

int	ft_exit(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	char			*s;
	long long		res;
	int				i;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	s = (char *)str;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res != ((res * 10) + (str[i] - '0')) / 10)
			return ((sign + 1) / -2);
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_is_numeric(char **argv, int i, int j)
{
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
