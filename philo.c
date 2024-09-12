/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 00:37:39 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static	void	freeve(struct philo *p, int status)
{
	free(p->data);
	exit(status);
}

void	philosophers(struct philo *p, char **argv)
{
	everinit(p, argv);
//	p->data->test = eating;
//	wthestate(p->data->test); 
	if (p->status)
	{
		free(p->data);
		exit(1);
	}	
}

int	main(int argc, char **argv, char **envp)
{	
	struct philo	philo;

	(void)envp;
	if (argc != 5 && argc != 6)
		printf("need ./philosophers + 4 || 5 args\n");
	else
	{
		philosophers(&philo, argv);
		freeve(&philo, philo.status);
	}
	return (0);
}
