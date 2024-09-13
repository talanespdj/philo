/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 17:50:46 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	philosophers(struct philo *p)
{
	int	i;

	i = -1;
	while (++i < p->data->n_philo)
	{
		p->phl[i] = (t_phl *)malloc(sizeof(t_phl));
		if (!p->phl[i])
			wgas(p, sstatus(p, i));
		p->phl[i]->state = init;
		p->phl[i]->id = i + 1;
//		pthread_create(p->phl[i]->thread, NULL, (*routine), p->phl[i]);
	}
}

int	main(int argc, char **argv, char **envp)
{	
	struct philo	p;

	(void)envp;
	if (argc != 5 && argc != 6)
		printf("need ./philosophers + 4 || 5 args\n");
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
