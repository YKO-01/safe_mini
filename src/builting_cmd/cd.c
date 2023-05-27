/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:12:54 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/24 18:11:14 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
