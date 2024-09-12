/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 01:21:30 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/wait.h>

typedef enum w_state
{
	eating,
	sleeping,
	thinking
}		t_state;

typedef struct philo
{
	struct data	*data;
	int			status;
}			t_philo;

typedef struct data
{
	enum w_state	test;
	char		**argv;
	int				n_agonist;
	int				n_fork;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
}			t_data;

typedef struct trd
{
}		t_trd;

void				everinit(struct philo *p, char **argv);

int					sstatus(struct philo *p, int d);
void				wthestate(enum w_state state);

int					talanatoi(struct philo *p, char *str, int d);

#endif
