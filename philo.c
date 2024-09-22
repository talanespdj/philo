/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/22 18:44:53 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philosophers(struct philo *p)
{
	int	i;
	size_t		laps = ttime(p);

	i = 0;
	// pthread_create(&p->phl[0]->thread, NULL, &surveil, (void *)p);
	while (++i <= p->n_philo)
	{
		p->phl[0]->id = i;
		pthread_create(&p->phl[i]->thread, NULL, &momeseno, (void *)p->phl);
		usleep(84);
	}
	printf("\t\t%zu\n", ttime(p) - laps);
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
		// printf("quoiquoiquoiquoiquoi\n");
		// printf("le time au debut de la boucle qui cree les threads des philo%zu\n", ttime(&p));
		// printf("le time au debut de la boucle qui cree les threads des philo\n");
		philosophers(&p);
		wgas(&p, 0);
	}
	return (0);
}
