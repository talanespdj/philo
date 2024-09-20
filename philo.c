/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/20 20:55:13 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philosophers(struct philo *p)
{
	int	i;

	i = 0;
	// pthread_create(&p->phl[0]->thread, NULL, &surveil, (void *)p);
	// printf("le time au debut de la boucle qui cree les threads des philo%zu\n", ttime(p));
	while (++i <= p->n_philo)
	{
//		pthread_mutex_lock(&p->phl[0]->mtx);
		p->phl[0]->id = i;
//		pthread_mutex_unlock(&p->phl[0]->mtx);
		pthread_create(&p->phl[i]->thread, NULL, &momeseno, (void *)p->phl);
		usleep(42);
	}
	// printf("\n\napres tout ca%zu\n", ttime(p));
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
		// printf("quoiquoiquoiquoiquoi\n");
		// printf("le time au debut de la boucle qui cree les threads des philo%zu\n", ttime(&p));
		// printf("le time au debut de la boucle qui cree les threads des philo\n");
		philosophers(&p);
		wgas(&p, 0);
	}
	return (0);
}
