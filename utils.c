/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:11:06 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/28 02:27:08 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

time_t	ttime(time_t tstart)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000 + t.tv_usec / 1000) - tstart);
}

static time_t	pc_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	tusleep(time_t mls)
{
	time_t			start;

	start = pc_time();
	while ((pc_time() - start) < mls)
		usleep(500);
}

void	writeft(struct phl *phl, t_sit sit)
{
	time_t	tstart;

	tstart = ttime(phl->tstart);
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
