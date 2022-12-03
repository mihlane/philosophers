/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabibi- <mhabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:55:48 by mhabibi-          #+#    #+#             */
/*   Updated: 2022/12/03 01:51:27 by mhabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_init	*ft_init_philos(t_init *info, char **av, int ac)
{
	info->num_of_philos = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->start = my_gettimes(0);
	info->eating = my_gettimes(info->start);
	info->ch7al_kla = 0;
	if (ac == 6)
		info->num_of_eat = ft_atoi(av[5]);
	else
		info->num_of_eat = 0;
	return (info);
}

void	ft_initial(t_list *data, char **av, int ac)
{
	data->info = malloc(sizeof(t_init));
	data->info = ft_init_philos(data->info, av, ac);
}

t_list	*create_node(int num)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->next = NULL;
	new_node->num = num;
	return (new_node);
}

void	ft_init(t_list **node, int num)
{
	t_list	*new_node;
	t_list	*tmp;

	tmp = *node;
	new_node = create_node(num);
	if (*node == NULL)
	{
		*node = new_node;
		return ;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < 48 || av[i][j] > 57) && av[i][0] != '+')
			{
				printf("arguments are wrong\n");
				return (0);
			}
			else if (av[i][0] == '+' && (av[i][1] < 48 || av[i][1] > 57))
			{
				printf("arguments are wrong\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
