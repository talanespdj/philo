/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:11:06 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/23 15:50:43 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"


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

void	writeft(struct phl *phl, t_sit sit)
{
	time_t	tstart;

	tstart = ttime(phl->tstart);
	if (sit == debug)
	{
		printf("\033[0;93m%zu %d\tDEBUG TIME\n\033[0m", tstart, phl->id);
		return ;
	}
	pthread_mutex_lock(&phl->phl_mtx);
	if (phl->health == dead)
	{
		pthread_mutex_unlock(&phl->phl_mtx);
		return ;
	}
	pthread_mutex_unlock(&phl->phl_mtx);
	pthread_mutex_lock(phl->write_mtx);
	if (sit == take)
		printf("%zu %d has taken a fork\n", tstart, phl->id);
	if (sit == SLEEP)
		printf("%zu %d is sleeping\n", tstart, phl->id);
	if (sit == THINK)
		printf("%zu %d is thinking\n", tstart, phl->id);
	if (sit == EAT)
		printf("%zu %d is eating\n", tstart, phl->id);
	pthread_mutex_unlock(phl->write_mtx);
}
