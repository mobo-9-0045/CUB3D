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

char	*remove_spaces(char *str)
{
	char	*paths;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			j++;
		i++;
	}
	paths = ft_substr(str, 0, ft_strlen(str) - j);
	return (paths);
}

int	paths_valid(t_var *var)
{
	char	*paths;
	char	*valid_paths;

	var->map_elmnt = ft_split(var->map, '\n');
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		paths = ft_strrchr(var->map_elmnt[var->i], '.');
		if (!paths)
			return (1);
		valid_paths = remove_spaces(paths);
		if (ft_strcmp(valid_paths, "./path_to_the_south_texture") == 0)
			var->path_so = valid_paths;
		else if (ft_strcmp(valid_paths, "./path_to_the_north_texture") == 0)
			var->path_no = valid_paths;
		else if (ft_strcmp(valid_paths, "./path_to_the_east_texture") == 0)
			var->path_ea = valid_paths;
		else if (ft_strcmp(valid_paths, "./path_to_the_west_texture") == 0)
			var->path_we = valid_paths;
		free (valid_paths);
		var->i++;
	}
	return (0);
}
