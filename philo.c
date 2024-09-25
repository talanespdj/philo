/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/25 16:35:28 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philosophers(struct philo *p)
{
	int			i;
	// void			*rtval = NULL;

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
		
	}
	else
	{
		pthread_create(&p->death, NULL, &surveil, (void *)p);
		while (++i < p->n_philo)
			pthread_create(&p->phl[i]->thread, NULL, &momeseno, (void *)p->phl[i]);
		pthread_join(p->death, NULL);
	}
}

int	main(int argc, char **argv)
{	
	struct philo	p;
	
	if (argc != 5 && argc != 6)
		printf("need ./philo + 4 || 5 args\n");
	else
	{
		everinit(&p, argv);
		if (p.situation)
			wgas(&p, p.situation);
		philosophers(&p);
		wgas(&p, 0);
	}
	return (0);
}
