/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:00:11 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

//structs

typedef struct s_info{
	int					num_philos;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;
	int					num_eats;
	int					num_readers_stop;
	int					num_readers_eats;
	unsigned long int	start_prog_milisec;
	unsigned long int	start_checker_microsec;
	int					all_ate;
}	t_info;

typedef struct s_sems{
	sem_t				*print;
	sem_t				*all_ate;
	sem_t				*forks;
}	t_sems;

typedef struct s_sems_philo{
	char				*all_ate_checker_name;
	sem_t				*all_ate_checker;
	char				*state_name;
	sem_t				*state;
	char				*last_eat_name;
	sem_t				*last_eat;
}	t_sems_philo;

typedef struct s_philo{
	t_info				*info;
	int					id;
	int					state;
	unsigned long int	last_eat;
	int					num_eats;
	int					wait_all_ate;
	pthread_t			philo_checker;
	struct timeval		time;
	struct s_philo		*next;
	struct s_philo		*prev;
	t_sems				*sems;
	t_sems_philo		sems_philo;
}	t_philo;

typedef struct s_academy{
	t_info			info;
	t_philo			*list;
	int				*processes;
	t_sems			sems;
}	t_academy;

// argv matrix

char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *str);
void				*ft_calloc(size_t count, size_t size);
long long int		ft_atoll(const char *str);
int					ft_atoi(const char *str);
int					num_words(char **argv);
int					num_char(char const *s, char c);
char				**matrix_argv(char **argv);
void				free_matrix(char **matrix);

//utils

char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

// lst functions

t_philo				*ft_lstnew(int id, t_academy *academy);
int					ft_lstsize(t_philo *philos);
void				ft_lstadd_back(t_philo **philos, t_philo *new);
void				ft_lstadd_front(t_philo **philos, t_philo *new);
t_philo				*ft_lstlast(t_philo *philos);
void				ft_lstcircle(t_philo **philos, t_philo *new);
t_philo				*ft_lstcirclelast(t_philo *philos);
void				free_circle_list(t_philo **head, int num);

// academy functions

void				set_academy(t_academy *academy, int argc, char **argv);
void				kill_processes(int	*processes_pid, int num_processes);
void				set_sems(t_academy *academy);
void				set_philo_lst_sems(t_philo	**philo);
void				close_sem(t_academy *academy);
void				unlink_sem(void);
void				free_philo_lst_sems(t_philo **philo);
void				end_program(t_academy *academy);

// time functions

unsigned long int	get_miliseconds(t_philo *philo);
void				ft_usleep(t_philo *philo, int sleep);

// philosophers algorithm

void				*philosophers(t_philo *philo);
void				think_philo(t_philo *philo);
void				try_eat_philo(t_philo *philo);
t_philo				*get_fork(t_philo *p1, t_philo *p2, int num_fork);
int					take_fork(t_philo *philo);
void				release_fork(t_philo *philo);
void				eat_philo(t_philo *philo);
void				sleep_philo(t_philo *philo);

// getters and setters

void				set_state(t_philo *philo, int state);
int					get_state(t_philo *philo);
void				set_wait_all_ate(t_philo *philo, int wait);
int					get_wait_all_ate(t_philo *philo);
void				set_last_eat(t_philo *philo, unsigned long int last_eat);
unsigned long int	get_last_eat(t_philo *philo);

// print

void				print_message(t_philo *philo, char *message);
void				print_death(t_philo *philo);

// checkers 

int					check_int_limits(char	**args);
void				check_death(t_philo *philo);
void				rest_check(t_philo *philo, int rest);
void				all_ate_checker(t_philo *philo);
void				*take_forks_checker(void *philo_data);

#endif