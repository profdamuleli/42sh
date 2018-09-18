/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstgethead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:12:57 by ngbanza           #+#    #+#             */
/*   Updated: 2017/09/07 10:13:06 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstgethead(t_dlist *dlst)
{
	while (dlst)
	{
		if (dlst->prev)
			dlst = dlst->prev;
		else
			break ;
	}
	return (dlst);
}
