/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:11:06 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 16:51:22 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	putstrfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	wthestate(enum w_state state)
{
	if (state == eating)
		printf("le philosophe est en train de eating\n");
	if (state == sleeping)
		printf("le philosophe est en train de sleeping\n");
	else if (state == thinking)
		printf("le philosophe est en train de thinking\n");
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
