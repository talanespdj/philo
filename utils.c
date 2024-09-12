/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:11:06 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 00:46:46 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	wthestate(enum w_state state)
{
	if (state == eating)
		printf("le philosophe est en train de eating\n");
	if (state == sleeping)
		printf("le philosophe est en train de sleeping\n");
	else if (state == thinking)
		printf("le philosophe est en train de thinking\n");
}

int	talanatoi(struct philo *p, char *str)
{
	long long int	nt;
	int				i;

	i = 0;
	nt = 0;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			return (sstatus(p, 42));
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nt = nt * 10 + (str[i] - 48);
		i++;
	}
	if (nt > 2147483647 || nt <= 0)
		return (sstatus(p, 42));
	return (nt);
}
