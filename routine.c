/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/28 03:04:57 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdint.h>

int	valid(struct phl *phl)
{
	pthread_mutex_lock(&phl->phl_mtx);
	if (phl->health == alive && ((phl->ntteat == -1)
			|| (phl->ntteat != -1 && phl->ntiate <= phl->ntteat)))
	{
		pthread_mutex_unlock(&phl->phl_mtx);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&phl->phl_mtx);
		return (0);
	}
}

void	*momeseno(void *philo)
{
	struct phl	*phl;

	phl = (struct phl *)philo;
	if (!(phl->id % 2 == 0))
		usleep(500);
	while (valid(phl))
	{
		eat(phl);
		pthread_mutex_lock(&phl->phl_mtx);
		if ((phl->ntteat != -1 && phl->ntiate == phl->ntteat))
		{
			pthread_mutex_unlock(&phl->phl_mtx);
			return (NULL);
		}
		pthread_mutex_unlock(&phl->phl_mtx);
		writeft(phl, SLEEP);
		tusleep(phl->tt_sleep);
		writeft(phl, THINK);
	}
	return (NULL);
}

void	*surveil(void *philo)
{
	struct philo	*p;
	time_t			t;
	int				i;

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
			return (handle_death(p, i));
		i++;
	}
}

void	*handle_death(struct philo *p, int i)
{
	int	r;

	r = -1;
	pthread_mutex_lock(&p->write_mtx);
	while (++r < p->n_philo)
	{
		pthread_mutex_lock(&p->phl[r]->phl_mtx);
		p->phl[r]->health = dead;
		pthread_mutex_unlock(&p->phl[r]->phl_mtx);
	}
	printf("%zu %d died\n", ttime(p->tstart), i + 1);
	pthread_mutex_unlock(&p->write_mtx);
	return (NULL);
}

void	eat(struct phl *phl)
{
	pthread_mutex_lock(&phl->r_fork->mtx);
	phl->r_fork->state = taken;
	writeft(phl, take);
	pthread_mutex_lock(&phl->fork.mtx);
	phl->fork.state = taken;
	writeft(phl, take);
	pthread_mutex_lock(&phl->phl_mtx);
	phl->lastteating = ttime(phl->tstart);
	pthread_mutex_unlock(&phl->phl_mtx);
	writeft(phl, EAT);
	tusleep(phl->tt_eat);
	phl->fork.state = available;
	pthread_mutex_unlock(&phl->fork.mtx);
	phl->r_fork->state = available;
	pthread_mutex_unlock(&phl->r_fork->mtx);
	phl->ntiate++;
}
