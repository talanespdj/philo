/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/25 20:17:30 by tespandj         ###   ########.fr       */
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
	while (22)
	{
		pthread_mutex_lock(&phl->fork.mtx);
		if ((phl->health == alive && (phl->ntteat == -1)) || (phl->ntteat != -1 && phl->ntiate <= phl->ntteat))
		{
			pthread_mutex_unlock(&phl->fork.mtx);
			pthread_mutex_lock(phl->write_mtx);
			printf("je passe\n");
			pthread_mutex_unlock(phl->write_mtx);
			eat(phl);
			pthread_mutex_lock(&phl->fork.mtx);
			if ((phl->ntteat != -1 && phl->ntiate == phl->ntteat))
			{
				pthread_mutex_unlock(&phl->fork.mtx);
				return (NULL);
			}
			pthread_mutex_unlock(&phl->fork.mtx);
			think(phl);
			zzsleep(phl);
		}
		else
		{
			pthread_mutex_unlock(&phl->fork.mtx);
			return (NULL);
		}
	}
	return (NULL);
}

void	*surveil(void *philo)
{
	struct philo	*p;
	int				i;
	int				r;
	time_t				t;

	i = -1;
	r = -1;
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
			pthread_mutex_lock(&p->write_mtx);
			while (++r < p->n_philo)
			{
				pthread_mutex_lock(&p->phl[r]->fork.mtx);
				p->phl[r]->health = dead;
				pthread_mutex_unlock(&p->phl[r]->fork.mtx);
			}
			printf("\033[0;92m\t\t%zu %d died\n\033[0m", ttime(p->tstart), i);
			pthread_mutex_unlock(&p->write_mtx);
			return (NULL);
		}
	}
	return (NULL);
}

//		if (ttime - p->phl[i]->lastteating > p->tt_die)
//			printf("%zu %d died\n", ttime, i);
