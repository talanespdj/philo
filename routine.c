/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/29 20:30:11 by tespandj         ###   ########.fr       */
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
			return (death(p, i));
		i++;
	}
}

void	*death(struct philo *p, int i)
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
	r = -1;
	while (++r < p->n_philo && p->ntteat != -1)
	{
		if (p->phl[r]->ntiate != p->ntteat)
			break ;
		if (r == p->n_philo - 1 && p->phl[r]->ntiate == p->ntteat)
		{
			printf("// everyone ate their fill\n");
			pthread_mutex_unlock(&p->write_mtx);
			return (NULL);
		}
	}
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
