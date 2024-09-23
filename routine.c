/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:56:42 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/23 20:34:41 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
#include <stdint.h>

void	*momeseno(void *philo)
{
	struct phl	*phl;
	int			i;

	phl = (struct phl *)philo;
	i = phl->id;
//	printf("[%d]\t, je pointe sur thread // [%d]\n", phl->fork.id, phl->r_fork->id); 
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
	int				i;
	size_t				t;

	i = 1;
	p = (struct philo *)philo;
	while (i < p->n_philo + 1)
	{
		if (i == p->n_philo)
			i = 0;
		t = ttime() - p->phl[i]->lastteating;
		if (t > p->tt_die)
		{
			tusleep(10000);
			printf("%zu %d died\n", ttime(), i);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}

//		if (ttime - p->phl[i]->lastteating > p->tt_die)
//			printf("%zu %d died\n", ttime, i);
