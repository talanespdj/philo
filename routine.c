/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/26 21:32:30 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdint.h>

void	*momeseno(void *philo)
{
	struct phl	*phl;

	phl = (struct phl *)philo;
	if (!(phl->id % 2 == 0))
		usleep(500);
	while (22)
	{
		pthread_mutex_lock(&phl->phl_mtx);
		if (phl->health == alive && ((phl->ntteat == -1) || (phl->ntteat != -1 && phl->ntiate <= phl->ntteat)))
		{
			pthread_mutex_unlock(&phl->phl_mtx);
			eat(phl);
			pthread_mutex_lock(&phl->phl_mtx);
			if ((phl->ntteat != -1 && phl->ntiate == phl->ntteat))
			{
				pthread_mutex_unlock(&phl->phl_mtx);
				return (NULL);
			}
			pthread_mutex_unlock(&phl->phl_mtx);
			zzsleep(phl);
			writeft(phl, THINK);
		}
		else
		{
			pthread_mutex_unlock(&phl->phl_mtx);
			return (NULL);
		}
	}
}

void	*surveil(void *philo)
{
	struct philo	*p;
	int				i;
	int				r;
	time_t					t;

	i = 0;
	p = (struct philo *)philo;
	while (22)
	{
		if (i == p->n_philo)
			i = 0;
		pthread_mutex_lock(&p->phl[i]->phl_mtx);
		t = ttime(p->tstart) - p->phl[i]->lastteating;
		pthread_mutex_unlock(&p->phl[i]->phl_mtx);
		if (t > p->tt_die)
		{
			r = -1;
			pthread_mutex_lock(&p->write_mtx);
			printf("\033[0;92m//////////////  %zu %d died  //////////////\n\033[0m", ttime(p->tstart), i + 1);
			while (++r < p->n_philo)
			{
				printf("WHATS HAPPENING\tphilo %d\n", r + 1);
				writeft(p->phl[r], debug);
				pthread_mutex_lock(&p->phl[r]->phl_mtx);
				p->phl[r]->health = dead;
				pthread_mutex_lock(&p->phl[r]->phl_mtx);
			}
			pthread_mutex_unlock(&p->write_mtx);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}

