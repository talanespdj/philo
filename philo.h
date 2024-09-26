/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/26 03:58:14 by tespandj         ###   ########.fr       */
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
	taken,
}		t_state;

typedef enum w_health
{
	alive,
	dead,
}		t_health;

typedef struct fork
{
	pthread_mutex_t		mtx;
	enum w_state		state;
	int					id;
}			t_fork;

typedef struct philo
{
	pthread_mutex_t		death_mtx;
	pthread_mutex_t		write_mtx;
	pthread_t			death;
	struct phl			**phl;
	time_t				tstart;
	int					situation;
	int					ntteat;
	int					pair;
	int					n_philo;
	time_t				tt_die;
	time_t				tt_eat;
	time_t				tt_sleep;
}			t_philo;

typedef struct phl
{
	enum w_health		health;
	pthread_t			thread;
	struct fork			fork;
	struct fork			*r_fork;
	pthread_mutex_t		*death_mtx;
	pthread_mutex_t		*write_mtx;
	int					id;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					ntiate;
	int					ntteat;
	time_t				tstart;
	time_t				lastteating;
}			t_phl;

void				philosophers(struct philo *p);

void				*momeseno(void *philo);
void				*surveil(void *philo);

void				everinit(struct philo *p, char **argv);
void				fill_phl(struct philo *p, char **av, int i);
time_t				ttime(time_t tstart);
void				tusleep(time_t mls);
time_t				pc_time(void);
void				putstrfd(char *str, int fd);

void				zzsleep(struct phl *phl);
void				think(struct phl *phl);
void				eat(struct phl *phl);
int				death(struct phl *phl);

void				wgas(struct philo *p, int status);
void				fphl(struct philo *p, int d);
int					sstatus(struct philo *p, int d);

int					talanatoi(struct philo *p, char *str, int d);

#endif
