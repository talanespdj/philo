/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/28 06:37:08 by tespandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum w_state
{
	available,
	taken
}		t_state;

typedef enum w_sit
{
	EAT,
	THINK,
	SLEEP,
	take
}		t_sit;

typedef enum w_health
{
	alive,
	dead
}		t_health;

typedef struct fork
{
	pthread_mutex_t		mtx;
	enum w_state		state;
	int					id;
}			t_fork;

typedef struct philo
{
	pthread_mutex_t		write_mtx;
	struct phl			**phl;
	pthread_t			liso;
	int					n_philo;
	time_t				tt_die;
	time_t				tt_eat;
	time_t				tt_sleep;
	time_t				tstart;
	int					ntteat;
	int					situation;
}			t_philo;

typedef struct phl
{
	pthread_t			thread;
	int					id;
	enum w_health		health;
	pthread_mutex_t		phl_mtx;
	pthread_mutex_t		*write_mtx;
	struct fork			fork;
	struct fork			*r_fork;
	time_t				tt_die;
	time_t				tt_eat;
	time_t				tt_sleep;
	time_t				tstart;
	time_t				lastteating;
	int					ntiate;
	int					ntteat;
}			t_phl;

void				philosophers(struct philo *p);

void				everinit(struct philo *p, char **av, int i);
void				fill_phl(struct philo *p, char **av, int i);

void				*momeseno(void *philo);
void				*surveil(void *philo);
int					valid(struct phl *phl);
void				*handle_death(struct philo *p, int i);

void				def_eat(struct phl *phl);
void				rev_eat(struct phl *phl);

void				wgas(struct philo *p, int status);
void				fphl(struct philo *p, int d);
time_t				ttime(time_t tstart);
void				tusleep(time_t mls);
int					sstatus(struct philo *p, int d);

int					talanatoi(struct philo *p, char *str, int d);
void				writeft(struct phl *phl, t_sit sit);

#endif
