/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:46:07 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/25 20:23:05 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	eat(struct phl *phl)
{
	pthread_mutex_lock(&phl->r_fork->mtx);
	phl->r_fork->state = taken;
	pthread_mutex_lock(phl->write_mtx);
	printf("%zu %d has taken a fork\n", ttime(phl->tstart), phl->id);
	pthread_mutex_unlock(phl->write_mtx);
	pthread_mutex_lock(&phl->fork.mtx);
	phl->fork.state = taken;
	pthread_mutex_lock(phl->write_mtx);
	printf("%zu %d has taken a fork\n", ttime(phl->tstart), phl->id);
	printf("\033[0;93m%zu %d is eating\n\033[0m", ttime(phl->tstart), phl->id);
	pthread_mutex_unlock(phl->write_mtx);
	tusleep(phl->tt_eat);
	phl->lastteating = ttime(phl->tstart); //
	phl->fork.state = available;
	pthread_mutex_unlock(&phl->fork.mtx);
	phl->r_fork->state = available;
	pthread_mutex_unlock(&phl->r_fork->mtx);
	phl->ntiate++;
}

void	think(struct phl *phl)
{
	pthread_mutex_lock(phl->write_mtx);
	printf("\033[0;94m%zu %d is thinking\n\033[0m", ttime(phl->tstart), phl->id);
	pthread_mutex_unlock(phl->write_mtx);
}

void	zzsleep(struct phl *phl)
{
	pthread_mutex_lock(phl->write_mtx);
	printf("\033[0;91m%zu %d is sleeping\n\033[0m", ttime(phl->tstart), phl->id);
	pthread_mutex_unlock(phl->write_mtx);
	tusleep(phl->tt_sleep);
}
