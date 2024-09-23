/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/22 22:26:01 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philosophers(struct philo *p)
{
	size_t		laps = ttime(p);
	int	i = -1;

//	pthread_create(&p->phl[0]->thread, NULL, &surveil, (void *)p);
//	while (1)
	while (++i < p->n_philo)
	{
		pthread_create(&p->phl[i]->thread, NULL, &momeseno, (void *)p->phl[i]);
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
//		philosophers(&p);
		wgas(&p, 0);
	}
	return (0);
}
