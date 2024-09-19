/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgas.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:48:11 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/19 23:44:21 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	wgas(struct philo *p, int status)
{
	if (status >= 0)
	{
		if (status == 0)
			free_phl(p, p->n_philo);
		else
			free_phl(p, p->situation);
	}
	else if (status == -1)
		putstrfd("verif args, must be numbers > 0\n", 2);
	else if (status == 20)
		putstrfd("gettimeofday failed\n", 2);
	exit(status);
}

void	verif(struct philo *p)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == p->n_philo)
			i = 0;
		i++;
	}
}

//		if (ttime - p->phl[i]->lastteating > p->tt_die)
//			printf("%zu %d died\n", ttime, i);

void	free_phl(struct philo *p, int d)
{
	int	i;

	i = -1;
	while (++i < p->n_philo && i <= d)
		free(p->phl[i]);
	free(p->phl);
}

int	sstatus(struct philo *p, int d)
{
	p->situation = d;
	return (d);
}
