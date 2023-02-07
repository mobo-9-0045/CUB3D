/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:38 by aomman            #+#    #+#             */
/*   Updated: 2023/02/07 15:35:02 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_errors(t_var *var, char **argv)
{
	if (check_map(var, argv) == 1)
	{
		free (var);
		return (1);
	}
	paths_valid(var);
	if (check_texture(var) == 1)
		return (1);
	if (check_colors(var) == 1)
		return (1);
	return (0);
}
