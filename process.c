/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 01:21:55 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	putstrfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	everinit(struct philo *p, char **av)
{
	p->data = (t_data *)malloc(sizeof(t_data));
	if (!p->data)
		exit(EXIT_FAILURE);
	p->status = 0;
	p->data->n_agonist = talanatoi(p, av[1], 1);
	p->data->n_fork = talanatoi(p, av[2], 2);
	p->data->tt_die = talanatoi(p, av[3], 3);
	p->data->tt_eat = talanatoi(p, av[4], 4);
	p->data->argv = av;
	if (av[5])
		p->data->tt_sleep = talanatoi(p, av[5], 5);
	if (p->status == 42)
		putstrfd("verif args, must be numbers > 0\n", 2);
}
