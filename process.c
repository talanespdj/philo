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
	p->tstart = ttime();
	p->situation = 0;
	p->pair = 0;
	p->n_philo = talanatoi(p, av[1], 1);
	p->tt_die = talanatoi(p, av[2], 2);
	p->tt_eat = talanatoi(p, av[3], 3);
	p->tt_sleep = talanatoi(p, av[4], 4);
	if (av[5])
		p->ntteat = talanatoi(p, av[5], 5);
	if (p->situation == 42)
		wgas(p, -1);
	if (p->n_philo % 2 == 0)
		p->pair = 1;
	p->phl = (t_phl **)malloc(sizeof(t_phl *) * (p->n_philo));
	if (!p->phl)
		wgas(p, -1);
	fill_phl(p, av);
}

void	fill_phl(struct philo *p, char **av)
{
	int		i;

	i = -1;
	while (++i < p->n_philo)
	{
		p->phl[i] = (t_phl *)malloc(sizeof(t_phl));
		if (!p->phl[i])
			wgas(p, sstatus(p, i));
		pthread_mutex_init(&p->phl[i]->mtx, NULL);
		p->phl[i]->tt_die = p->tt_die;
		p->phl[i]->tt_eat = p->tt_eat;
		p->phl[i]->tt_sleep = p->tt_die;
		if (av[5])
			p->phl[i]->ntteat  = p->ntteat;
		p->phl[i]->id = i;
		p->phl[i]->fork = 0;
		p->phl[i]->ntiate = 0;
		p->phl[i]->lastteating = 0;
	}
}

size_t	ttime(void)
{
	struct timeval		t;

	gettimeofday(&t, NULL);
	return ((size_t)((t.tv_usec / 1000) + (t.tv_sec * 1000)));
}

size_t	lasttime(t_phl phl)
{
	size_t	t;

	t = ttime();
	return (t - phl.lastteating);
}

void	putstrfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}