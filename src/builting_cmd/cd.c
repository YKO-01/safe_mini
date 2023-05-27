/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:12:54 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/27 22:01:57 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	change_dir(t_list *lst)
{

	lst = lst->next;
	while (lst->data->token == 3)
		lst = lst->next;
	while (lst)
	{
		chdir(lst->data->content);
		lst = lst->next;
	}
}
