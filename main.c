/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrank <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:34:59 by rfrank            #+#    #+#             */
/*   Updated: 2020/10/05 20:35:00 by rfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_param	g_map_param = {0, 0, 0, 0, 0};
t_sq	g_square = {0, 0, 0};

void	solve_exmpl(int fd)
{
	char **map;

	read_params(fd);
	if (!g_map_param.x || !g_map_param.obst
		|| !g_map_param.full || !g_map_param.empty)
		return (map_error());
	map = (char**)malloc(sizeof(char*) * g_map_param.x + 2);
	read_first_line(map, fd);
	if (!g_map_param.x)
		return ;
	ft_memory(map);
	read_map(map, fd, 1, 0);
	if (!g_map_param.x)
		return ;
	bsq(map);
	print_map(map);
}

int		main(int ac, char **av)
{
	int fd;
	int i;

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		solve_exmpl(fd);
		close(fd);
		reset_globals();
		i++;
	}
	if (ac == 1)
		solve_exmpl(0);
	return (0);
}
