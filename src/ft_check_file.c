/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 08:27:44 by ngbanza           #+#    #+#             */
/*   Updated: 2017/10/01 08:28:08 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int			ft_check_file(char *str, int *ret)
{
	int		i;
	int		check_bool;

	i = -1;
	check_bool = 0;
	while (str[++i] && !check_bool)
	{
		if (str[i] == '>' && str[i + 1] == '>')
		{
			*ret = FILE_APPEND;
			check_bool = 1;
		}
		if (str[i] == '>' && str[i + 1] != '>')
		{
			*ret = FILE_OUT;
			check_bool = 1;
		}
		if (str[i] == '<' && str[i + 1] != '<')
		{
			*ret = FILE_IN;
			check_bool = 1;
		}
	}
	return (i);
}
