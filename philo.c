/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:40:17 by mhabibi-          #+#    #+#             */
/*   Updated: 2022/12/03 02:11:41 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_eating(t_list *philo)
{
	if (philo->info->ch7al_kla > philo->info->num_of_eat)
		return (1);
	else
		return (0);
}

int	ft_true(t_list *data)
{
	while (data)
	{
		pthread_mutex_lock(data->death);
		if ((my_gettimes(data->info->start)
				- data->info->eating) >= data->info->time_to_die)
		{
			pthread_mutex_lock(data->write);
			printf("%llu philosopher %d died\n",
				(my_gettimes(data->info->start)), data->num);
			return (0);
		}
		if (check_eating(data))
			return (0);
		pthread_mutex_unlock(data->death);
		data = data->next;
	}
	return (1);
}

void	init_all(t_list *datta, char **av, int ac)
{
	t_list	*data;
	t_list	*tmp;
	int		i;

	i = 0;
	data = datta;
	tmp = data;
	while (i++ < ft_atoi(av[1]))
	{
		ft_initial(data, av, ac);
		pthread_mutex_init(&data->fork, NULL);
		data = data->next;
	}
	data = tmp;
	while (data->next)
		data = data->next;
	data->next = tmp;
	data = tmp;
}

int	main(int ac, char **av)
{
	t_list			*data;
	pthread_mutex_t	*mute;
	t_list			*tmp;
	int				i;

	data = NULL;
	i = 0;
	if (ac < 5 || ac > 6 || (ac == 6 && ft_atoi(av[5]) <= 0))
		return (0);
	if (check_args(ac, av) == 0)
		return (0);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0)
		return (0);
	while (i++ < ft_atoi(av[1]))
		ft_init(&data, i);
	tmp = data;
	mute = malloc(sizeof(pthread_mutex_t) * 3);
	pthread_mutex_init(&mute[0], NULL);
	pthread_mutex_init(&mute[1], NULL);
	pthread_mutex_init(&mute[2], NULL);
	init_all(data, av, ac);
	set_mut_thread(data, mute);
	ft_true(data);
	return (0);
}
