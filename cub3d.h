/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:43:25 by aomman            #+#    #+#             */
/*   Updated: 2023/02/05 18:43:27 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include<fcntl.h>
# include<mlx.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>

typedef struct s_var
{
	int		i;
	int		j;
	char	*map;
	char	**map_elmnt;
}	t_var;

void	ft_putstr(char *str, int fd);
char	*ft_strrchr(const char *str, int c);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
int		check_map(t_var *var, char **argv);
int		valid_map_is_valid(t_var *var);
int		ft_strlen(const char *str);

#endif
