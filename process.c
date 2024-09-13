/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 16:53:56 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	everinit(struct philo *p, char **av)
{
	p->data = (t_data *)malloc(sizeof(t_data));
	if (!p->data)
		exit(EXIT_FAILURE);
	p->situation = 0;
	p->data->n_philo = talanatoi(p, av[1], 1);
	p->data->n_fork = talanatoi(p, av[2], 2);
	p->data->tt_die = talanatoi(p, av[3], 3);
	p->data->tt_eat = talanatoi(p, av[4], 4);
	p->data->argv = av;
	if (av[5])
		p->data->tt_sleep = talanatoi(p, av[5], 5);
	if (p->situation == 42)
		putstrfd("verif args, must be numbers > 0\n", 2);
	p->phl = (t_phl **)malloc(sizeof(t_phl) * (p->data->n_philo));
	if (!p->phl)
		wgas(p, -1);
	init_phl(p);
}

void	init_phl(struct philo *p)
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
	}
}
