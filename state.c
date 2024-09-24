/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:46:07 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/23 15:48:28 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	eat(struct philo *phl, int i)
{
	pthread_mutex_lock(&phl->r_fork->mtx);
	phl->r_fork->state = taken;
	printf("%zu %d has taken a fork\n", ttime(p), phl->id);
	pthread_mutex_lock(&phl->fork.mtx);
	phl->fork->state = taken;
	printf("%zu %d has taken a fork\n", ttime(p), phl->id);
	printf("%zu %d is eating\n", ttime(p), phl[i]->id);
	phl->lastteating = ttime(p);
	tusleep(p->tt_eat);
	phl->fork->state = available;
	pthread_mutex_unlock(&phl->fork.mtx);
	phl->r_fork->state = available;
	pthread_mutex_unlock(&phl->r_fork->mtx);
}

void	think(struct philo *p, int i)
{
	printf("%zu %d is thinking\n", ttime(p), phl->id);
}

void	zzsleep(struct philo *phl, int i)
{
	printf("%zu %d is sleeping\n", ttime(p), phl->id);
	tusleep(phl->tt_sleep);
}
