/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 22:08:26 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/06 22:10:51 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	everinit(struct philo *philo, char **argv)
{
	n_agonist = talanatoi(argv[1]);
	n_fork = talanatoi(argv[2]);
	tt_die = talanatoi(argv[3]);
	tt_eat = talanatoi(argv[4]);
	tt_sleep = talanatoi(argv[5]);
}
