/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 21:22:49 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*philosopher(void *philo)
{
	struct	philo	*p;
	int	i;
	int	d;

	// while (1 )
	p = (struct philo *)philo;
	p->i = 0;
	i = 0;
	d = p->i + 1;
	if (d == p->data->n_philo)
		d = 0;
	if (p->phl[i]->state == thinking)
	{
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
	else if (p->phl[i]->state == eating)
	{
		p->phl[d]->fork = 0;
		p->phl[i]->fork = 0;
		p->phl[i]->state = eating;
		printf("%d is thinking\n", p->phl[i]->id);
		pthread_mutex_unlock(&p->phl[i]->mtx);
	}
	// else if (p->phl[i]->state == )	
	pthread_mutex_destroy(&p->phl[i]->mtx);
	return (p);
}

int	main(int argc, char **argv)
{	
	struct philo	p;

	if (argc != 5 && argc != 6)
		printf("need ./philosophers + 4 || 5 args\n");
	else
	{
		everinit(&p, argv);
		if (p.situation)
			wgas(&p, p.situation);
		wgas(&p, 0);
	}
	return (0);
}
