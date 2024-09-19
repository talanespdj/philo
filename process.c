/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/19 19:57:26 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	everinit(struct philo *p, char **av)
{
	gettimeofday(&p->tmptime, NULL);
	printf("\t\t\t\tmicrosecondes start == %ld\n", p->tmptime.tv_usec);
	p->tstart= p->tmptime.tv_usec;
	sleep(3);
	gettimeofday(&p->tmptime, NULL);
	printf("tstart == %ld, tmptime.tv_sec == %ld\n", p->tstart, p->tmptime.tv_sec);
	printf("il y a eu un laps de temps de %ld sec\n", mtime(p) - p->tstart);
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
	p->phl = (t_phl **)malloc(sizeof(t_phl) * (p->n_philo));
	if (!p->phl)
		wgas(p, -1);
	init_phl(p, -1);
	fill_phl(p);
}

void	init_phl(struct philo *p, int i)
{
	while (++i < p->n_philo)
	{
		p->phl[i] = (t_phl *)malloc(sizeof(t_phl));
		if (!p->phl[i])
			wgas(p, sstatus(p, i));
		pthread_mutex_init(&p->phl[i]->mtx, NULL);
		p->phl[i]->id = i + 1;
		p->phl[i]->fork = 0;
	}
}

void	fill_phl(struct philo *p)
{
	int	i;

	i = -1;
	while (++i < p->n_philo)
	{
		p->i = i;
		pthread_create(&p->phl[i]->thread, NULL, &philosopher, (void *)p);
		pthread_join(p->phl[i]->thread, NULL);
	}
}
