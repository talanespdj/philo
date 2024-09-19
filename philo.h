/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/19 19:58:08 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef enum w_state
{
	eating,
	sleeping,
	thinking,
	died,
}		t_state;

typedef struct philo
{
	struct timeval	tmptime;
	struct phl		**phl;
	long			tstart; // time auquel tout a commencé
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				meals;
	int				situation;
	int				pair;
	int				i;
}			t_philo;

typedef struct phl
{
	enum w_state		state;
	pthread_mutex_t		mtx;
	pthread_t			thread;
	long				lastteating; //combien de time qu'il n'a pas eat
	int					fork;
	int					id;
}			t_phl;

void				*philosopher(void *philo);

long				mtime(struct philo *p);

void				everinit(struct philo *p, char **argv);
void				init_phl(struct philo *p, int i);
void				fill_phl(struct philo *p);

void				wgas(struct philo *p, int status);
void				free_phl(struct philo *p, int d);
int					sstatus(struct philo *p, int d);

void				putstrfd(char *str, int fd);
void				wthestate(enum w_state state);
int					talanatoi(struct philo *p, char *str, int d);

#endif
