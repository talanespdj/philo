/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/12 22:44:39 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	everinit(struct philo *p, char **argv, char *const *envp)
{
	p->data = (t_data *)malloc(sizeof(t_data));
	if (!p->data)
		exit(EXIT_FAILURE);
	p->data->n_agonist = talanatoi(p, argv[1]);
	p->data->n_fork = talanatoi(p, argv[2]);
	p->data->tt_die = talanatoi(p, argv[3]);
	p->data->tt_eat = talanatoi(p, argv[4]);
	if (argv[6])
		p->data->tt_sleep = talanatoi(p, argv[6]);
/*	
	p->data->n_agonist = atoi(argv[1]);
	p->data->n_fork = atoi(argv[2]);
	p->data->tt_die = atoi(argv[3]);
	p->data->tt_eat = atoi(argv[4]);
	if (argv[5])
		p->data->tt_sleep = atoi(argv[5]);*/
	p->data->env = envp;
	p->status = 0;
}
