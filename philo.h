/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/22 22:00:09 by tespandj         ###   ########.fr       */
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
	available,
	unavailable,
}		t_state;

typedef struct fork
{
	pthread_mutex_t		*fork;
	enum w_state		state;
}			t_fork;

typedef struct philo
{
	struct phl		**phl;
	size_t			tstart;
	int				n_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				ntteat;
	int				situation;
	int				pair;
}			t_philo;

typedef struct phl
{
	pthread_mutex_t		mtx;
	pthread_t			thread;
	int					fork;
	int					id;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					ntiate;
	int					ntteat;
	long				lastteating;
}			t_phl;

void				philosophers(struct philo *p);

void				*momeseno(void *philo);
void				*surveil(void *philo);

void				everinit(struct philo *p, char **argv);
void				fill_phl(struct philo *p, char **av);
size_t				ttime(void);
size_t				lasttime(t_phl phl);
void				putstrfd(char *str, int fd);

void				zzsleep(struct philo *p, int i);
void				think(struct philo *p, int i);
void				eat(struct philo *p, int i, int d);

void				wgas(struct philo *p, int status);
void				fphl(struct philo *p, int d);
int					sstatus(struct philo *p, int d);

int					talanatoi(struct philo *p, char *str, int d);

#endif
