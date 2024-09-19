/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/19 23:41:53 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*momeseno(void *philo)
{
	struct philo	*p;
	int				i;
	int				d;

	p = (struct philo *)philo;
	i = p->i;
	d = i + 1;
	if (d == p->n_philo)
		d = 0;
	while (le philo n'est pas mort)
	{
		choisir l'etat dans lequel il sera
	}
	return (NULL);
}

void	philosophers(struct philo *p)
{
	p->i = 0;
	while (p->situation != 999)
	{
		if (p->i == p->n_philo)
			p->i = 0;
		pthread_create(&p->phl[p->i]->thread, NULL, &momeseno, (void *)p);
		p->i++;
	}
}

int	main(int argc, char **argv)
{	
	struct philo	p;

	if (argc != 5 && argc != 6)
		printf("need ./philosophers + 4 || 5 args\n");
	else
	{
		everinit(&p, argv);
		if (p.situation)
			wgas(&p, p.situation);
		philosophers(&p);
		wgas(&p, 0);
	}
	return (0);
}
