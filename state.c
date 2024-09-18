/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:46:07 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/18 19:38:13 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void    wasthinking(struct philo *p, int i, int d)
{
	if (i == p->data->n_philo)
		i = 0;
	d = i + 1;
	if (d == p->data->n_philo)
		d = 0;
	pthread_mutex_lock(&p->phl[i]->mtx);
	if (d == 0)
	{
		p->phl[i]->fork = 1;
		p->phl[d]->fork = 1;
	}
	else
	{
		p->phl[d]->fork = 1;
		p->phl[i]->fork = 1;
	}
	printf("%d has taken a fork\n", p->phl[i]->id);
	printf("%d has taken a fork\n", p->phl[i]->id);
	p->phl[i]->state = eating;
	printf("%d is eating\n", p->phl[i]->id);
	//pthread_mutex_unlock(&p->phl[i]->fork);
}

void	waseating(struct philo *p, int i, int d)
{
	p->phl[d]->fork = 0;
	p->phl[i]->fork = 0;
	p->phl[i]->state = eating;
	printf("%d is thinking\n", p->phl[i]->id);
	pthread_mutex_unlock(&p->phl[i]->mtx);
}

// void	wassleeping(struct philo *p, int i, int d)
// {

