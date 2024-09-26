/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/26 18:49:11 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdint.h>

void	*momeseno(void *philo)
{
	struct phl	*phl;

	phl = (struct phl *)philo;
	if (!(phl->id % 2 == 0))
		tusleep(phl->tt_eat);
	while (22)
	{
		pthread_mutex_lock(&phl->fork.mtx);
		if ((phl->health == alive && (phl->ntteat == -1)) || (phl->ntteat != -1 && phl->ntiate <= phl->ntteat))
		{
			pthread_mutex_unlock(&phl->fork.mtx);
			eat(phl);
			pthread_mutex_lock(&phl->fork.mtx);
			if ((phl->ntteat != -1 && phl->ntiate == phl->ntteat))
			{
				pthread_mutex_unlock(&phl->fork.mtx);
				return (NULL);
			}
			pthread_mutex_unlock(&phl->fork.mtx);
//			if (!death(phl))
				zzsleep(phl);
//			if (!death(phl))
				think(phl);
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

	i = 0;
	p = (struct philo *)philo;
	r = -1;
	while (22)
	{
		if (i == p->n_philo)
			i = 0;
		pthread_mutex_lock(p->phl[i]->death_mtx);
		t = ttime(p->tstart) - p->phl[i]->lastteating;
		pthread_mutex_unlock(p->phl[i]->death_mtx);
	//	printf("\t\t\tt = %zu\n", t);
		// if (!(t > p->tt_die)) 
			// pthread_mutex_unlock(p->phl[i]->death_mtx);
		if (t > p->tt_die)
		{
			pthread_mutex_lock(&p->write_mtx);
			printf("\033[0;92m\t\t%zu %d died // lastteating %zu\ttt_die // %zu\n\033[0m", ttime(p->tstart), i, p->phl[i]->lastteating, p->tt_die);
			printf("\t\t\tt = %zu\n", t);
			while (++r < p->n_philo)
			{
				printf("WHATS HAPPENING\tphilo %d\n", r + 1);
				pthread_mutex_lock(&p->phl[r]->fork.mtx);
				p->phl[r]->health = dead;
				pthread_mutex_unlock(&p->phl[r]->fork.mtx);
			}
			//printf("\033[0;92m\t\t%zu %d died // lastteating %zu\ttt_die // %zu\n\033[0m", ttime(p->tstart), i, p->phl[i]->lastteating, p->tt_die);
			//printf("\t\t\tt = %zu\n", t);
			pthread_mutex_unlock(&p->write_mtx);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}

//		if (ttime - p->phl[i]->lastteating > p->tt_die)
//			printf("%zu %d died\n", ttime, i);
