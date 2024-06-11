/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:38:23 by shatan            #+#    #+#             */
/*   Updated: 2024/06/11 14:11:39 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_node	*new_node(void *ptr)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == 0)
	{
		ft_printf("Error\n\tNew node: failed_to_malloc\n");
		return (0);
	}
	new->ptr = ptr;
	new->next = 0;
	return (new);
}

void	ft_list_add(t_linked_list *list, void *ptr)
{
	t_node	*new;

	new = new_node(ptr);
	if (new == 0)
		return ;
	new->next = list->head;
	list->head = new;
}

void	ft_list_remove(t_linked_list *list, void *ptr)
{
	t_node	*current;
	t_node	*prev;

	current = list->head;
	prev = 0;
	while (current != 0)
	{
		if (current->ptr == ptr)
		{
			if (prev == 0)
				list->head = current->next;
			else
				prev->next = current->next;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

void	ft_free_list(t_linked_list *list, void (*free_func)(void *))
{
	t_node	*current;
	t_node	*next;

	current = list->head;
	while (current != 0)
	{
		next = current->next;
		free_func(current->ptr);
		free(current);
		current = next;
	}
	list->head = 0;
}
