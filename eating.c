/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 06:57:39 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/28 06:57:49 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	def_eat(struct phl *phl)
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

void	rev_eat(struct phl *phl)
{
	pthread_mutex_lock(&phl->fork.mtx);
	phl->fork.state = taken;
	writeft(phl, take);
	pthread_mutex_lock(&phl->r_fork->mtx);
	phl->r_fork->state = taken;
	writeft(phl, take);
	pthread_mutex_lock(&phl->phl_mtx);
	phl->lastteating = ttime(phl->tstart);
	pthread_mutex_unlock(&phl->phl_mtx);
	writeft(phl, EAT);
	tusleep(phl->tt_eat);
	phl->r_fork->state = available;
	pthread_mutex_unlock(&phl->r_fork->mtx);
	phl->fork.state = available;
	pthread_mutex_unlock(&phl->fork.mtx);
	phl->ntiate++;
}
