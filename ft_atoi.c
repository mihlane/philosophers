/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:46:37 by mhabibi-          #+#    #+#             */
/*   Updated: 2022/11/29 16:05:09 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	f;
	int	z;
	int	k;

	i = 0;
	z = 1;
	k = 0;
	if (str[i] == '-')
	{
		z = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10;
		f = (str[i] - '0');
		k = k + f;
		i++;
	}
	return (k * z);
}
