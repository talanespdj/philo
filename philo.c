/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 21:22:49 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*philosopher(void *philo)
{
////		j'envoie toute la structure pour pouvoir acceder aux fourchettes des autres
////		pour savoir de quel philo on s'occupe il y a p->i qui nous donne l'index
////			du philo dans le tableau (en commencant par 0 jusque p->data->n_philo - 1)
	struct	philo	*p;
	int	i;
	int	d;

	p = (struct philo *)philo;
	i = p->i;
	d = i + 1;
	if (d == p->data->n_philo)
		d = 0;
	pthread_mutex_init(&p->phl[i]->mutex, NULL);
	if (p->phl[i]->state == thinking)
	{
		pthread_mutex_lock(&p->phl[i]->mutex);
		p->phl[d]->fork = 1;
		printf("%d has taken a fork\n", i + 1);
		p->phl[i]->fork = 1;
		printf("%d has taken a fork\n", i + 1);
		printf("%d is eating\n", i + 1);
		pthread_mutex_unlock(&p->phl[i]->mutex);
	}
	return (p);

}

int	main(int argc, char **argv, char **envp)
{	
	struct philo	p;

	(void)envp;
	if (argc != 5 && argc != 6)
		printf("need ./philosophers + 4 || 5 args\n");
	else
	{
		everinit(&p, argv);
		if (p.situation)
			wgas(&p, p.situation);
		wgas(&p, 0);
	}
	return (0);
}
