/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:03:09 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/10 12:15:36 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/time.h>

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
	int					stop;
	unsigned long int	curr_time;
	struct timeval		time_struct;
	int					print;
}	t_info;

typedef struct s_philo{
	t_info				*info;
	pthread_mutex_t		*print_mutex;
	pthread_mutex_t		*all_eats;
	pthread_mutex_t		*stop;
	pthread_mutex_t		*time;
	pthread_mutex_t		fork_mutex;
	int					id;
	int					state;
	int					fork;
	int					dead;
	unsigned long int	last_eat;
	int					num_eats;
	struct s_philo		*next;
	struct s_philo		*prev;
}	t_philo;

typedef struct s_academy{
	t_info			info;
	t_philo			*list;
	pthread_t		*threads;
	pthread_t		time_thread;
	pthread_t		life_thread;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	all_eats;
	pthread_mutex_t	time;
	pthread_mutex_t	stop;
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
void				end_program(t_academy *academy);

// time functions

unsigned long int	get_miliseconds(t_philo *philo);
unsigned long int	get_time(t_philo *philo);
void				*time_check(void *academy);
unsigned long int	ft_usleep(t_philo *philo, unsigned long int rest);

// philosophers algorithm

void				*philosophers(void *philo_data);
void				think_philo(t_philo *philo);
void				try_eat_philo(t_philo *philo);
t_philo				*get_fork(t_philo *p1, t_philo *p2, int num_fork);
int					take_fork(t_philo *fork, t_philo *philo);
void				release_fork(t_philo *philo);
void				eat_philo(t_philo *philo);
void				sleep_philo(t_philo *philo);

// getters and setters

void				set_stop(t_philo *philo, int value, int mode);
int					get_stop(t_philo *philo);
void				set_all_eats(t_philo *philo);

// print

void				print_message(t_philo *philo, char *message);
void				print_death(t_philo *philo);

// checkers 

int					check_int_limits(char	**args);
void				philo_checker(t_academy *academy);
int					check_death(t_philo *philo);
void				rest_check(t_philo *philo, int rest, int state);
void				stop_checker(t_philo *philo);

#endif