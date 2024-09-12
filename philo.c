/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:32 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/06 22:06:23 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	philosophers(struct philo *philo, char **argv, char *const *envp)
{
	everinit(philo, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{	
	struct philo	philo;

	if (argc != 6)
		putstr("need ./philosophers + 5 args\n");
	else
		philosophers(&philo, argv, envp);
	return (0);
}
