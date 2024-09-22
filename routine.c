/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/22 22:28:04 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*momeseno(void *philo)
{
	struct phl	*phl;
	int				i;

	phl = (struct phl *)philo;
	i = phl->id;
	printf("%d\n", phl->right_phl->fork);
//	while (le philo n'est pas mort)
//	{
// 		choisir l'etat dans lequel il sera
// 		void	zzsleep(struct philo *p, int i);
// 		void	think(struct philo *p, int i);
// 		void	eat(struct philo *p, int i, int d);
//	}
	return (NULL);
}

void	*surveil(void *philo)
{
	struct philo	*p;
	int			i;
	int			t;

	i = 1;
	p = (struct philo *)philo;
	while (1)
	{
		if (i > p->n_philo)
			i = 1;
		t = ttime(p) - p->phl[i]->lastteating;
		if (t > p->tt_die)
			wgas(p, sstatus(p, 999));
		i++;		
	}
	return (NULL);
}
