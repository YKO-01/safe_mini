/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:33:54 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/23 17:54:28 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	// if (*lst)
	// 	ft_lstlast(*lst)->next = new;
	// else
	// 	*lst = new;
	t_list	*temp;

	if (!(*lst))
		*lst = new;
	temp = ft_lstlast(*lst);
	temp->next = new;
	new->next = NULL;
}
