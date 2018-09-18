/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstremoveif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngbanza <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 10:14:07 by ngbanza           #+#    #+#             */
/*   Updated: 2017/09/07 10:14:10 by ngbanza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstremoveif(t_dlist **head, int cmp())
{
	t_dlist	*ptr;

	while (*head)
	{
		if (cmp((*head)->content, (*head)->content_size))
		{
			if ((*head)->prev)
				(*head)->prev->next = (*head)->next;
			if ((*head)->next)
				(*head)->next->prev = (*head)->prev;
			ptr = *head;
			*head = (*head)->prev ? (*head)->prev : (*head)->next;
			free(ptr->content);
			free(ptr);
		}
		head = &(*head)->next;
	}
}
