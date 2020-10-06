/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:35:09 by rfrank            #+#    #+#             */
/*   Updated: 2020/10/05 20:35:11 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_square(char **map)
{
	int i;
	int j;
	int k;
	int s;

	k = 0;
	i = g_square.x - g_square.size;
	while (k++ < g_square.size)
	{
		s = 0;
		j = g_square.y - g_square.size;
		while (s++ < g_square.size)
			map[i][j++] = g_map_param.full;
		i++;
	}
}

void	print_map(char **map)
{
	int i;
	int j;
	int k;
	int s;

	k = g_square.x - g_square.size;
	s = g_square.y - g_square.size;
	i = 0;
	while (*(map[i]))
	{
		j = 0;
		while (map[i][j])
		{
			if (i == k && j == s)
				print_square(map);
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
