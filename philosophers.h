/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/06 22:48:59 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/wait.h>

typedef struct philo
{
	struct data	*data;
	int			status;
}			t_philo;

typedef struct data
{
	int		n_agonist;
	int		n_fork;
	int		tt_die;
	int		tt_eat;
	int		tt_sleep;
	char *const	*env;
}			t_data;

void				everinit(struct philo *p, char **argv, char *const *envp);

int				sstatus(struct philo *p, int d);

void				putstr(char *str);
int				talanatoi(struct philo *p, char *str);

#endif
