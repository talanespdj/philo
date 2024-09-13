/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 02:54:32 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	putstrfd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

static void	f_phl(struct philo *p)
{
	int	i;

	i = 0;
	while (++i <= p->data->n_philo)
	{
		free(p->phl);
		p->phl = p->phl->next;
	}
	p->phl = NULL;
}

static void	aff_index(struct philo *p)
{
	t_phl	*temp;

	temp = p->phl;
	while (temp)
	{
		printf("%d\n", temp->index);
		temp = temp->next;
	}
}

static void	init_phl(struct philo *p)
{
	t_phl	*current;
	t_phl	*tmp = NULL;
	int	i;

	i = 0;
	while (++i <= p->data->n_philo)
	{
		current = (t_phl *)malloc(sizeof(t_phl));
		if (!current)
			return ;
		current->index = i;
		printf("%d\n", current->index);
		current->state = init;
		current->next = tmp;
		tmp = current;
	}
	p->phl = tmp;
}

void	everinit(struct philo *p, char **av)
{
	p->data = (t_data *)malloc(sizeof(t_data));
	if (!p->data)
		exit(EXIT_FAILURE);
	p->situation = 0;
	p->data->n_philo = talanatoi(p, av[1], 1);
	p->data->n_fork = talanatoi(p, av[2], 2);
	p->data->tt_die = talanatoi(p, av[3], 3);
	p->data->tt_eat = talanatoi(p, av[4], 4);
	p->data->argv = av;
	if (av[5])
		p->data->tt_sleep = talanatoi(p, av[5], 5);
	if (p->situation == 42)
		putstrfd("verif args, must be numbers > 0\n", 2);
	p->phl = (t_phl *)malloc(sizeof(t_phl));
	if (!p->phl)
		wgas(p, p->situation);
	init_phl(p);
	aff_index(p);
	f_phl(p);
}

