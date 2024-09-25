/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/24 22:28:41 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	everinit(struct philo *p, char **av)
{
	struct timeval		t;

	gettimeofday(&t, NULL);
	p->tstart = t.tv_sec * 1000 + t.tv_usec / 1000;
	p->situation = 0;
	p->n_philo = talanatoi(p, av[1], 1);
	p->tt_die = talanatoi(p, av[2], 2);
	p->tt_eat = talanatoi(p, av[3], 3);
	p->tt_sleep = talanatoi(p, av[4], 4);
	if (av[5])
		p->ntteat = talanatoi(p, av[5], 5);
	pthread_mutex_init(&p->write_mtx, NULL);
	if (p->situation == 42)
		wgas(p, -1);
	p->pair = 0;
	if (p->n_philo % 2 == 0)
		p->pair = 22;
	p->phl = (t_phl **)malloc(sizeof(t_phl *) * (p->n_philo));
	if (!p->phl)
		wgas(p, -1);
	fill_phl(p, av, -1);

}

void	fill_phl(struct philo *p, char **av, int i)
{
	while (++i < p->n_philo)
	{
		p->phl[i] = (t_phl *)malloc(sizeof(t_phl));
		if (!p->phl[i])
			wgas(p, sstatus(p, i));
		p->phl[i]->p = p;
		p->phl[i]->id = i + 1;
		p->phl[i]->health = alive;
		p->phl[i]->tstart = p->tstart;
		p->phl[i]->lastteating = 0;
		p->phl[i]->tt_die = p->tt_die;
		p->phl[i]->tt_eat = p->tt_eat;
		p->phl[i]->tt_sleep = p->tt_die;
		p->phl[i]->ntteat = -1;
		if (av[5])
			p->phl[i]->ntteat = p->ntteat;
		p->phl[i]->fork.id = i;
		p->phl[i]->ntiate = 0;
		pthread_mutex_init(&p->phl[i]->fork.mtx, NULL);
	}
	i = -1;
	while (++i < p->n_philo)
	{
		if (i == p->n_philo - 1)
			p->phl[i]->r_fork = &p->phl[0]->fork;
		else
			p->phl[i]->r_fork = &p->phl[i + 1]->fork;
	}
}

time_t	ttime(time_t tstart)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000 + t.tv_usec / 1000) - tstart);
}

void	tusleep(time_t mls)
{
	struct timeval t;
	time_t	start;

	gettimeofday(&t, NULL);
	start = (t.tv_sec * 1000 + t.tv_usec / 1000);
	while ((pc_time() - start) < mls)
		usleep(500);
}

time_t	pc_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

/*size_t	reset_time(t_phl phl)
{
	size_t	t;

	t = ttime();
	return (t - phl.lastteating);
}*/

void	putstrfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}
