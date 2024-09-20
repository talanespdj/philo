/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:46:07 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/19 23:36:37 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	eat(struct philo *p, int i, int d)
{
	pthread_mutex_lock(&p->phl[i]->mtx);
	p->phl[d]->fork = 1;
	p->phl[i]->fork = 1;
	printf("%zu %d has taken a fork\n", ttime(p), p->phl[i]->id);
	printf("%zu %d has taken a fork\n", ttime(p), p->phl[i]->id);
	printf("%zu %d is eating\n", ttime(p), p->phl[i]->id);
	p->phl[i]->state = eating;
//////		fonction pour convertir mlsec en micro
//	usleep(function(p->tt_eat));
	p->phl[i]->lastteating = ttime(p);
	p->phl[d]->fork = 0;
	p->phl[i]->fork = 0;
	pthread_mutex_unlock(&p->phl[i]->mtx);
}

void	think(struct philo *p, int i)
{
	p->phl[i]->state = thinking;
	printf("%zu %d is thinking\n", ttime(p), p->phl[i]->id);
}

void	zzsleep(struct philo *p, int i)
{
	p->phl[i]->state = sleeping;
	printf("%zu %d is sleeping\n", ttime(p),p->phl[i]->id);
//////		fonction pour convertir mlsec en micro
//	usleep(function(p->tt_sleep));
}
