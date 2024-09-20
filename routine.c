/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/20 19:53:41 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*momeseno(void *phl)
{
	struct phl	**philo;
	int				i;
	int				d;

	philo = (struct phl **)phl;
	i = philo[0]->id;
	d = i + 1;
	if (!philo[d])
		d = 0;
	printf("%d\n", philo[0]->id);
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
