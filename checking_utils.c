/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:51:53 by aomman            #+#    #+#             */
/*   Updated: 2023/02/05 18:51:54 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return (s + i);
		i--;
	}
	return (s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	_s1 = (unsigned char *) s1;
	_s2 = (unsigned char *) s2;
	i = 0;
	while (_s1[i])
	{
		if (!(_s1[i] == _s2[i] && _s1[i] != '\0' && _s2[i] != '\0'))
			return (_s1[i] - _s2[i]);
		i++;
	}
	return (0);
}
