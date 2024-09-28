/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/28 02:27:01 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	everinit(struct philo *p, char **av, int i)
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
	if (p->situation == 42)
		wgas(p, -1);
	pthread_mutex_init(&p->write_mtx, NULL);
	p->phl = (t_phl **)malloc(sizeof(t_phl *) * (p->n_philo));
	if (!p->phl)
		wgas(p, -2);
	fill_phl(p, av, -1);
	while (++i < p->n_philo - 1)
		p->phl[i]->r_fork = &p->phl[i + 1]->fork;
	p->phl[i]->r_fork = &p->phl[0]->fork;
	// p->phl[i]->r_fork = &p->phl[i]->fork;
	// p->phl[i]->fork = p->phl[0]->fork;
}

void	fill_phl(struct philo *p, char **av, int i)
{
	while (++i < p->n_philo)
	{
		p->phl[i] = (t_phl *)malloc(sizeof(t_phl));
		if (!p->phl[i])
			wgas(p, sstatus(p, i));
		p->phl[i]->id = i + 1;
		p->phl[i]->health = alive;
		p->phl[i]->tstart = p->tstart;
		p->phl[i]->tt_die = p->tt_die;
		p->phl[i]->tt_eat = p->tt_eat;
		p->phl[i]->tt_sleep = p->tt_sleep;
		p->phl[i]->ntteat = -1;
		if (av[5])
			p->phl[i]->ntteat = p->ntteat;
		p->phl[i]->fork.id = i + 1;
		p->phl[i]->ntiate = 0;
		p->phl[i]->lastteating = 0;
		p->phl[i]->write_mtx = &p->write_mtx;
		pthread_mutex_init(&p->phl[i]->phl_mtx, NULL);
		pthread_mutex_init(&p->phl[i]->fork.mtx, NULL);
	}
}

void	wgas(struct philo *p, int status)
{
	int	i;

	i = -1;
	if (status == -1)
		printf("verif args, must be numbers > 0\n");
	if (status == -2)
		pthread_mutex_destroy(&p->write_mtx);
	if (status == -1 || status == -2)
		exit(status);
	while (++i < p->n_philo && p->n_philo != 1)
	{
		pthread_mutex_destroy(&p->phl[i]->phl_mtx);
		pthread_mutex_destroy(&p->phl[i]->fork.mtx);
	}
	pthread_mutex_destroy(&p->write_mtx);
	if (status == 0)
		fphl(p, p->n_philo);
	else if (status)
		fphl(p, p->situation);
	exit(status);
}

void	fphl(struct philo *p, int d)
{
	int	i;

	i = -1;
	while (++i < p->n_philo && i <= d)
		free(p->phl[i]);
	free(p->phl);
}

int	sstatus(struct philo *p, int d)
{
	p->situation = d;
	return (d);
}
