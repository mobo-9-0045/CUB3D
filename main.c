/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:27:03 by aomman            #+#    #+#             */
/*   Updated: 2023/02/05 18:43:01 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"cub3d.h"

void	ft_free(t_var *var)
{
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		free (var->map_elmnt[var->i]);
		var->i++;
	}
	free (var->map);
	free (var->map_elmnt);
}

int	main(int argc, char **argv)
{
	t_var	*var;

	if (argc == 2)
	{
		var = malloc(sizeof(t_var));
		if (check_map(var, argv) == 1)
		{
			free (var);
			return (0);
		}
		if (paths_valid(var) == 0)
			then_check_colors(var);
		ft_free (var);
		free (var);
	}
	else
		ft_putstr("programe accepet programe name + map path\n", 2);
	// while (1);
	return (0);
}
