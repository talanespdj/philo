/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/06 22:10:51 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	everinit(struct philo *p, char **argv)
{
	p->data = (t_data *)malloc(sizeof(t_data));
	if (!p->data)
		exit(EXIT_FAILURE);
	p->data->n_agonist = talanatoi(argv[1]);
	p->data->n_fork = talanatoi(argv[2]);
	p->data->tt_die = talanatoi(argv[3]);
	p->data->tt_eat = talanatoi(argv[4]);
	p->data->tt_sleep = talanatoi(argv[5]);
	p->status = 0;
}
