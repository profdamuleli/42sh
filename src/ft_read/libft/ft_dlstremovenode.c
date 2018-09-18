/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremovenode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:14:30 by ngbanza           #+#    #+#             */
/*   Updated: 2017/09/07 10:14:32 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstremovenode(t_dlist **head)
{
	t_dlist	*ptr;

	if (*head)
	{
		if ((*head)->prev)
			(*head)->prev->next = (*head)->next;
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		ptr = *head;
		*head = (*head)->next ? (*head)->next : (*head)->prev;
		free(ptr->content);
		free(ptr);
	}
}
