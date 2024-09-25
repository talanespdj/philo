/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/25 13:41:10 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdint.h>

void	*momeseno(void *philo)
{
	struct phl	*phl;

	phl = (struct phl *)philo;
	if (!(phl->id % 2 == 0))
		tusleep(2);
	while (phl->health == alive)
	{
//		pthread_mutex_lock(&phl->fork.mtx);
		if (phl->health == alive)
		{
//			pthread_mutex_unlock(&phl->fork.mtx);
			if ((phl->ntteat == -1) || (phl->ntteat != -1 && phl->ntiate <= phl->ntteat))
				eat(phl);
			think(phl);
			zzsleep(phl);
		}
	}
	return (NULL);
}

void	*surveil(void *philo)
{
	struct philo	*p;
	int				i;
	int				r = -1;
	time_t				t;

	i = 0;
	p = (struct philo *)philo;
	while (++i)
	{
		if (i == p->n_philo)
			i = 0;
		pthread_mutex_lock(&p->phl[i]->fork.mtx);
		t = p->phl[i]->lastteating - ttime(p->tstart);
		pthread_mutex_unlock(&p->phl[i]->fork.mtx);
		if (t > p->tt_die)
		{
			while (++r < p->n_philo)
			{
				pthread_mutex_lock(&p->phl[r]->fork.mtx);
				p->phl[r]->health = dead;
				pthread_mutex_unlock(&p->phl[r]->fork.mtx);
			}
			printf("%zu %d died\n", ttime(p->tstart), i);
			return (NULL);
		}
	}
	return (NULL);
}

//		if (ttime - p->phl[i]->lastteating > p->tt_die)
//			printf("%zu %d died\n", ttime, i);
