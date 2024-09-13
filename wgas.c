/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgas.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:48:11 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 19:40:24 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	wgas(struct philo *p, int status)
{
	if (status >= 0)
	{
		if (status == 0)
			free_phl(p, p->data->n_philo);
		else
			free_phl(p, p->situation);
	}
	free(p->data);
	exit(status);
}

void	free_phl(struct philo *p, int d)
{
	int	i;

	i = -1;
	while (++i < p->data->n_philo && i <= d)
		free(p->phl[i]);
	free(p->phl);
}

int	sstatus(struct philo *p, int d)
{
	p->situation = d;
	return (d);
}
