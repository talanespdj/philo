/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/22 22:25:34 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	everinit(struct philo *p, char **av)
{
	p->tstart = ttime(p);
	p->situation = 0;
	p->pair = 0;
	p->n_philo = talanatoi(p, av[1], 1);
	p->tt_die = talanatoi(p, av[2], 2);
	p->tt_eat = talanatoi(p, av[3], 3);
	p->tt_sleep = talanatoi(p, av[4], 4);
	if (av[5])
		p->meals = talanatoi(p, av[5], 5);
	if (p->situation == 42)
		wgas(p, -1);
	if (p->n_philo % 2 == 0)
		p->pair = 1;
	p->phl = (t_phl **)malloc(sizeof(t_phl *) * (p->n_philo));
	if (!p->phl)
		wgas(p, -1);
	init_phl(p, av, -1);
}

void	init_phl(struct philo *p, char **av, int i)
{
	while (++i < p->n_philo)
	{
		p->phl[i] = (t_phl *)malloc(sizeof(t_phl));
		if (!p->phl[i])
			wgas(p, sstatus(p, i));
		p->phl[i]->right_phl = p->phl[i + 1];
		if (i == p->n_philo - 1)
			p->phl[i]->right_phl = p->phl[0];
		pthread_mutex_init(&p->phl[i]->mtx, NULL);
		p->phl[i]->lastteating = 0;
		p->phl[i]->ntiate = 0;
		p->phl[i]->id = i;
		p->phl[i]->fork = 0;
		p->phl[i]->tt_die = talanatoi(p, av[2], 2);
		p->phl[i]->tt_eat = talanatoi(p, av[3], 3);
		p->phl[i]->tt_sleep = talanatoi(p, av[4], 4);
	}
}

size_t	lasttime(struct philo *p, int i)
{
	size_t	t;

	t = ttime(p);
	return (t - p->phl[i]->lastteating);
}
