/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/19 23:46:02 by tespandj         ###   ########.fr       */
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
	size_t			tstart;
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				meals;
	int				situation;
	int				pair;
}			t_philo;

typedef struct phl
{
	enum w_state		state;
	pthread_mutex_t		mtx;
	pthread_t			thread;
	long				lastteating;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					ntiate;
	int					ntteat;
	int					fork;
	int					id;
}			t_phl;

void				philosophers(struct philo *p);

void				*momeseno(void *philo);
void				*surveil(void *philo);

void				everinit(struct philo *p, char **argv);
void				init_phl(struct philo *p, char **av, int i);

void				zzsleep(struct philo *p, int i);
void				think(struct philo *p, int i);
void				eat(struct philo *p, int i, int d);

void				verif(struct philo *p);
void				wgas(struct philo *p, int status);
void				free_phl(struct philo *p, int d);
int					sstatus(struct philo *p, int d);

size_t				ttime(struct philo *p);
void				putstrfd(char *str, int fd);
int					talanatoi(struct philo *p, char *str, int d);

#endif
