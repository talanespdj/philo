/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 02:30:35 by tespandj         ###   ########.fr       */
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
	init,
	eating,
	sleeping,
	thinking
}		t_state;

typedef struct philo
{
	struct data	*data;
	struct phl	*phl;
	int			situation;
}			t_philo;

typedef struct data
{
	enum w_state	test;
	char			**argv;
	int				n_philo;
	int				n_fork;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
}			t_data;

typedef struct phl
{
	struct phl	*next;
	int			index;
	t_state		state;
}		t_phl;

void				everinit(struct philo *p, char **argv);

void				wgas(struct philo *p, int status);
int					sstatus(struct philo *p, int d);

void				wthestate(enum w_state state);
int					talanatoi(struct philo *p, char *str, int d);

#endif
