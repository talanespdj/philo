/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/18 16:05:32 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	everinit(struct philo *p, char **av)
{
	p->data = (t_data *)malloc(sizeof(t_data));
	if (!p->data)
		exit(EXIT_FAILURE);
	gettimeofday(&p->tmptime, NULL);
	p->tstart= p->tmptime.tv_sec;
	p->situation = 0;
	p->pair = 0;
	p->data->n_philo = talanatoi(p, av[1], 1);
	p->data->n_fork = talanatoi(p, av[2], 2);
	p->data->tt_die = talanatoi(p, av[3], 3);
	p->data->tt_eat = talanatoi(p, av[4], 4);
	p->data->argv = av;
	if (av[5])
		p->data->tt_sleep = talanatoi(p, av[5], 5);
	if (p->situation == 42)
		wgas(p, -1);
	if (p->data->n_philo % 2 == 0)
		p->pair = 1;
	p->phl = (t_phl **)malloc(sizeof(t_phl) * (p->data->n_philo));
	if (!p->phl)
		wgas(p, -1);
	init_phl(p, -1);
	fill_phl(p);
}

void	init_phl(struct philo *p, int i)
{
	while (++i < p->data->n_philo)
	{
		p->phl[i] = (t_phl *)malloc(sizeof(t_phl));
		if (!p->phl[i])
			wgas(p, sstatus(p, i));
		pthread_mutex_init(&p->phl[i]->mtx, NULL);
		p->phl[i]->state = thinking;
		p->phl[i]->id = i + 1;
		// p->phl[i]->fork = 0;
	}
}

void	fill_phl(struct philo *p)
{
	int	i;

	i = -1;
	while (++i < p->data->n_philo)
	{
		p->i = i;
		pthread_create(&p->phl[i]->thread, NULL, &philosopher, (void *)p);
		pthread_join(p->phl[i]->thread, NULL);
	}
}
