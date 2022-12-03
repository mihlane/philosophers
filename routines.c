/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:41:41 by mhabibi-          #+#    #+#             */
/*   Updated: 2022/12/01 00:09:55 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine2(t_list *helo)
{
	t_list	*habibi;

	habibi = helo;
	pthread_mutex_unlock(habibi->write);
	ft_sleep(habibi->info->time_to_eat);
	pthread_mutex_unlock(&habibi->fork);
	pthread_mutex_unlock(&habibi->next->fork);
	pthread_mutex_lock(habibi->write);
	printf("%llu philosopher %d is sleeping\n",
		(my_gettimes(habibi->info->start)), habibi->num);
	pthread_mutex_unlock(habibi->write);
	ft_sleep(habibi->info->time_to_sleep);
	pthread_mutex_lock(habibi->write);
	printf("%llu philosopher %d is thinking\n",
		(my_gettimes(habibi->info->start)), habibi->num);
	pthread_mutex_unlock(habibi->write);
}

void	*routine(void *helo)
{
	t_list	*habibi;

	habibi = helo;
	while (1)
	{
		pthread_mutex_lock(&habibi->fork);
		pthread_mutex_lock(habibi->write);
		printf("%llu philosopher %d has taken a fork\n",
			(my_gettimes(habibi->info->start)), habibi->num);
		pthread_mutex_unlock(habibi->write);
		pthread_mutex_lock(&habibi->next->fork);
		pthread_mutex_lock(habibi->write);
		printf("%llu philosopher %d has taken a fork\n",
			(my_gettimes(habibi->info->start)), habibi->num);
		pthread_mutex_unlock(habibi->write);
		pthread_mutex_lock(habibi->death);
		habibi->info->eating = my_gettimes(habibi->info->start);
		if (habibi->info->num_of_eat != 0)
			habibi->info->ch7al_kla += 1;
		pthread_mutex_unlock(habibi->death);
		pthread_mutex_lock(habibi->write);
		printf("%llu philosopher %d is eating\n",
			(my_gettimes(habibi->info->start)), habibi->num);
		routine2(habibi);
	}
}

void	set_mut_thread(t_list *data, pthread_mutex_t *mute)
{
	int		i;
	t_list	*tmp;

	tmp = data;
	i = 0;
	while (i++ < data->info->num_of_philos)
	{
		tmp->death = &mute[0];
		tmp->write = &mute[1];
		tmp->check = &mute[2];
		tmp = tmp->next;
	}
	i = 0;
	while (i++ < data->info->num_of_philos)
	{
		pthread_create(&data->thread, NULL, routine, data);
		pthread_detach(data->thread);
		usleep(50);
		data = data->next;
	}
}
