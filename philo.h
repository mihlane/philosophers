/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:40:07 by mhabibi-          #+#    #+#             */
/*   Updated: 2022/11/29 21:46:32 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philosophers
{
	int					num_of_philos;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					num_of_eat;
	int					dead_philos;
	int					ch7al_kla;
	unsigned long long	eating;
	long long int		start;
}						t_init;

typedef struct node
{
	pthread_mutex_t		*write;
	pthread_t			thread;
	pthread_mutex_t		fork;
	pthread_mutex_t		*death;
	pthread_mutex_t		*check;
	int					num;
	struct node			*next;
	t_init				*info;
}						t_list;

t_init					*ft_init_philos(t_init *info, char **av, int ac);
void					ft_initial(t_list *data, char **av, int ac);
t_list					*create_node(int num);
void					ft_init(t_list **node, int num);
int						check_args(int ac, char **av);
unsigned long long		my_gettimes(long long int start);
int						ft_atoi(const char *str);
void					ft_sleep(int time);
void					*routine(void *helo);
void					routine2(t_list *helo);
int						ft_true(t_list *data);
void					init_all(t_list *datta, char **av, int ac);
void					set_mut_thread(t_list *data, pthread_mutex_t *mute);

#endif
