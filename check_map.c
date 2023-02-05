/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:01:55 by aomman            #+#    #+#             */
/*   Updated: 2023/02/05 19:01:56 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_map(t_var *var, char **argv)
{
	int		fd_map;
	char	*map_ext;

	map_ext = ft_strrchr(argv[1], '.');
	if (ft_strcmp(map_ext, ".cub") != 0)
	{
		ft_putstr("map should must be .cub extention\n", 2);
		return (1);
	}
	fd_map = open (argv[1], O_RDONLY, 600);
	if (fd_map < 0)
	{
		ft_putstr("Error in map fd", 2);
		return (1);
	}
	var->map = get_next_line(fd_map);
	return (0);
}

int	check_left_and_up(t_var *var)
{
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		if (var->map_elmnt[var->i][0] != '1')
			return (1);
		var->j = 0;
		while (var->map_elmnt[var->i][var->j])
		{
			if (var->map_elmnt[0][var->j] != '1')
				return (1);
			var->j++;
		}
		var->i++;
	}
	return (0);
}

int	check_right_and_down(t_var *var)
{
	var->j = 0;
	while (var->map_elmnt[var->i - 1][var->j])
	{
		if (var->map_elmnt[var->i - 1][var->j] != '1')
			return (1);
		var->j++;
	}
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		if (var->map_elmnt[var->i][var->j - 1] != '1')
			return (1);
		var->i++;
	}
	return (0);
}

int	valid_map_is_valid(t_var *var)
{
	var->map_elmnt = ft_split(var->map, '\n');
	if (check_left_and_up(var) == 1)
		return (1);
	if (check_right_and_down(var) == 1)
		return (1);
	return (0);
}
