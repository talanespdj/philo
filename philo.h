/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tespandj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:47:51 by tespandj          #+#    #+#             */
/*   Updated: 2024/09/13 20:51:20 by tespandj         ###   ########.fr       */
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
	thinking,
	died,
}		t_state;

typedef struct philo
{
	struct phl	**phl;
	struct data	*data;
	int			situation;
	int			i;
}			t_philo;

typedef struct data
{
	char		**argv;
	int			n_philo;
	int			n_fork;
	int			tt_die;
	int			tt_eat;
	int			tt_sleep;
}			t_data;

typedef struct phl
{
	enum w_state	state;
	pthread_t		thread;
	pthread_mutex_t		mutex;
	int				id;
	int				fork;
}			t_phl;

void				*philosopher(void *philo);

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
