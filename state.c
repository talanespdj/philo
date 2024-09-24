/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:46:07 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/24 22:34:51 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	eat(struct phl *phl)
{
	pthread_mutex_lock(&phl->r_fork->mtx);
	phl->r_fork->state = taken;
	printf("%zu %d has taken a fork\n", ttime(phl->tstart), phl->id);
	pthread_mutex_lock(&phl->fork.mtx);
	phl->fork.state = taken;
	printf("%zu %d has taken a fork\n", ttime(phl->tstart), phl->id);
	printf("%zu %d is eating\n", ttime(phl->tstart), phl->id);
	phl->lastteating = ttime(phl->tstart);
	tusleep(phl->tt_eat);
	phl->fork.state = available;
	pthread_mutex_unlock(&phl->fork.mtx);
	phl->r_fork->state = available;
	pthread_mutex_unlock(&phl->r_fork->mtx);
	phl->ntiate++;
}

void	think(struct phl *phl)
{
	printf("%zu %d is thinking\n", ttime(phl->tstart), phl->id);
}

void	zzsleep(struct phl *phl)
{
	printf("%zu %d is sleeping\n", ttime(phl->tstart), phl->id);
	tusleep(phl->tt_sleep);
}
