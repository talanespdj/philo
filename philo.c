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

void	philosophers(struct philo *philo, char **argv, char **env)
{
	everinit(philo, argv);
}

int	main(int argc, char **argv, char **envp)
{	
	struct philo	philo;

	if (argc != 6 || !envp[0])
		return (0);
	else
		philosophers(&philo, argv, envp);
	return (0);
}
