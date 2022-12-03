/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:05:32 by mhabibi-          #+#    #+#             */
/*   Updated: 2022/11/29 16:57:47 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time)
{
	unsigned long long	time2;

	time2 = my_gettimes(0);
	while (my_gettimes(0) < time2 + time)
		usleep(400);
}

unsigned long long	my_gettimes(long long int start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000))
		- start);
}
