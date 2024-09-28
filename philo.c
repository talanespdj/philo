/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/28 06:38:31 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philosophers(struct philo *p)
{
	int	i;

	i = -1;
	if (p->n_philo == 1)
	{
		pthread_mutex_lock(&p->phl[0]->fork.mtx);
		p->phl[0]->fork.state = taken;
		printf("%zu %d has taken a fork\n", ttime(p->tstart), 1);
		while (ttime(p->tstart) < p->tt_die)
			i++;
		pthread_mutex_unlock(&p->phl[0]->fork.mtx);
		printf("%zu %d died\n", ttime(p->tstart), 1);
		wgas(p, 0);
	}
	pthread_create(&p->liso, NULL, &surveil, (void *)p);
	while (++i < p->n_philo)
		pthread_create(&p->phl[i]->thread, NULL, &momeseno, p->phl[i]);
	i = -1;
	while (++i < p->n_philo)
		pthread_join(p->phl[i]->thread, NULL);
	pthread_join(p->liso, NULL);
}

int	main(int argc, char **argv)
{	
	struct philo	p;

	if (argc != 5 && argc != 6)
		printf("need ./philo + 4 || 5 args\n");
	else
	{
		everinit(&p, argv, -1);
		if (p.situation)
			wgas(&p, p.situation);
		philosophers(&p);
		wgas(&p, 0);
	}
	return (0);
}
