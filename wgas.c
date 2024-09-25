/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wgas.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:48:11 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/25 20:21:26 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	wgas(struct philo *p, int status)
{
	int	i;

	i = -1;
	while (++i < p->n_philo && p->n_philo != 1)
	{
		pthread_join(p->phl[i]->thread, NULL);
		pthread_mutex_destroy(&p->phl[i]->fork.mtx);
	}
	pthread_mutex_destroy(&p->write_mtx);
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
