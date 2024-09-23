/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgas.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:48:11 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/23 15:49:19 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	wgas(struct philo *p, int status)
{
	int	i;
///////////// doit seulement attendre les threads s'ils ont tous ete crees
	i = -1;
	while (++i < p->n_philo)
	{
		pthread_join(p->phl[i]->thread, NULL);
		pthread_mutex_destroy(p->phl[i]->fork->mtx);
	}
	if (status >= 0)
	{
		if (status == 0)
			fphl(p, p->n_philo);
		else
			fphl(p, p->situation);
	}
	else if (status == -1)
		putstrfd("verif args, must be numbers > 0\n", 2);
	else if (status == 20)
		putstrfd("gettimeofday failed\n", 2);
	exit(status);
}

void	fphl(struct philo *p, int d)
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
