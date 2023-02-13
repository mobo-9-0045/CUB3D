/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:32:36 by aomman            #+#    #+#             */
/*   Updated: 2023/02/09 22:32:56 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	check_map_component(t_var *var)
{
	var->i = 0;
	while (var->map_elmnt[var->i])
	{
		printf("%s\n", var->map_elmnt[var->i]);
		var->i++;
	}
	return (0);
}

int	check_key_f(t_var *var)
{
	int	strlen_var;
	int	i;

	strlen_var = ft_strlen(var->map_elmnt[var->i]);
	i = 0;
	while (i < strlen_var)
	{
		if (var->map_elmnt[var->i][i] == 'F')
			break ;
		if (var->map_elmnt[var->i][i] > ' ')
			return (1);
		i++;
	}
	return (0);
}
