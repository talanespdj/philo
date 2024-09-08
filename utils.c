/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:11:06 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/06 22:11:31 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

static	int	sign(struct philo *p, int nt, char *str)
{
	int	s;
	int	i;

	i = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9')
		|| (nt > 2147483647 || nt < -2147483648))
		p->status = 42;
	return (s);
}

int	talanatoi(struct philo *p, char *str)
{
	long long int	nt;
	int				i;

	i = 0;
	nt = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nt = nt * 10 + (str[i] - 48);
		i++;
	}
	nt *= sign(p, nt, str);
	if (p->status == 42)
		return (0);
	return (nt);
}
