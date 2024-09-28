/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/28 08:07:26 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*momeseno(void *philo)
{
	struct phl	*phl;
	void		(*eat)(t_phl *phl);

	phl = (struct phl *)philo;
	eat = &def_eat;
	if (!(phl->id % 2 == 0))
	{
		eat = &rev_eat;
		usleep(500);
	}
	while (valid(phl))
	{
		eat(phl);
		pthread_mutex_lock(&phl->phl_mtx);
		if (phl->ntteat != -1 && phl->ntiate == phl->ntteat)
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
//	int	d;

	r = -1;
//	d = 0;
	pthread_mutex_lock(&p->write_mtx);
	while (++r < p->n_philo)
	{
//		if (p->ntteat != -1)
//			if (p->phl[r]->ntiate != p->ntteat)
//				d++;
		pthread_mutex_lock(&p->phl[r]->phl_mtx);
		p->phl[r]->health = dead;
		pthread_mutex_unlock(&p->phl[r]->phl_mtx);
	}
//	if (!d)
		printf("%zu %d died\n", ttime(p->tstart), i + 1);
	pthread_mutex_unlock(&p->write_mtx);
	return (NULL);
}

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
		return (pthread_mutex_unlock(&phl->phl_mtx));
}
