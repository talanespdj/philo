/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:46:07 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/26 21:36:25 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	eat(struct phl *phl)
{
	pthread_mutex_lock(&phl->r_fork->mtx);
	phl->r_fork->state = taken;
	writeft(phl, take);
	pthread_mutex_lock(&phl->fork.mtx);
	phl->fork.state = taken;
	writeft(phl, take);
	pthread_mutex_lock(&phl->phl_mtx);
	phl->lastteating = ttime(phl->tstart); //set le lastteating avant de faire le tusleep de tt_eat
	pthread_mutex_unlock(&phl->phl_mtx);
	writeft(phl, EAT);
	tusleep(phl->tt_eat);
	phl->fork.state = available;
	pthread_mutex_unlock(&phl->fork.mtx);
	phl->r_fork->state = available;
	pthread_mutex_unlock(&phl->r_fork->mtx);
	phl->ntiate++;
}

void	zzsleep(struct phl *phl)
{
	writeft(phl, SLEEP);
	tusleep(phl->tt_sleep);
}

// void	think(struct phl *phl)
// {
// 	pthread_mutex_lock(phl->write_mtx);
// 	if (phl->health == alive)
// 		printf("SI JE SUIS ALIVE JE PRINT QUE JE THINKAIS\n");
// 		// printf("\033[0;94m%zu %d is thinking\n\033[0m", ttime(phl->tstart), phl->id);
// 	pthread_mutex_unlock(phl->write_mtx);
// }

int	death(struct phl *phl)
{
	time_t		t;

	pthread_mutex_lock(phl->death_mtx);
	t = ttime(phl->tstart) - phl->lastteating;
	pthread_mutex_unlock(phl->death_mtx);
	if (t > phl->tt_die)
	{
		pthread_mutex_lock(&phl->fork.mtx);
		phl->health = dead;
		pthread_mutex_unlock(&phl->fork.mtx);
		return (0);
	}
	return (1);
}

// void	eat(struct phl *phl)
// {
// 	pthread_mutex_lock(&phl->r_fork->mtx);
// 	phl->r_fork->state = taken;
// 	pthread_mutex_lock(phl->write_mtx);
// 	printf("%zu %d has taken a fork\n", ttime(phl->tstart), phl->id);
// 	pthread_mutex_unlock(phl->write_mtx);
// 	while (1)
// 	{
// 		if (death(phl) == 0)
// 		{
// 			pthread_mutex_unlock(&phl->r_fork->mtx);
// 			return ;
// 		}
// 		if (pthread_mutex_lock(&phl->fork.mtx) == 0)
// 			break;
// 	}
// 	phl->fork.state = taken;
// 	pthread_mutex_lock(phl->write_mtx);
// 	printf("%zu %d has taken a fork\n", ttime(phl->tstart), phl->id);
// 	printf("\033[0;93m%zu %d is eating\n\033[0m", ttime(phl->tstart), phl->id);
// 	pthread_mutex_unlock(phl->write_mtx);
// 	phl->lastteating = ttime(phl->tstart); //set le lastteating avant de faire le tusleep de tt_eat
// 	tusleep(phl->tt_eat);
// 	phl->fork.state = available;
// 	pthread_mutex_unlock(&phl->fork.mtx);
// 	phl->r_fork->state = available;
// 	pthread_mutex_unlock(&phl->r_fork->mtx);
// 	phl->ntiate++;
// }
