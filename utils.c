/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:11:06 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/20 17:49:36 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

size_t	ttime(struct philo *p)
{
	struct timeval		t;

	if (gettimeofday(&t, NULL) != 0)
		wgas(p, 20);
	return ((size_t)((t.tv_usec / 1000) + (t.tv_sec * 1000)));
}

void	putstrfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	talanatoi(struct philo *p, char *str, int d)
{
	long int	nt;
	int			i;

	i = 0;
	nt = 0;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			return (sstatus(p, 42));
		i++;
	}
	if (d == 5)
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (sstatus(p, 42));
	while (str[i] >= '0' && str[i] <= '9')
	{
		nt = nt * 10 + (str[i] - 48);
		i++;
	}
	if (d != 5 && (nt > 2147483647 || nt <= 0))
		return (sstatus(p, 42));
	else if (d == 5)
		if (nt > 2147483647 || nt < 0)
			return (sstatus(p, 42));
	return (nt);
}
