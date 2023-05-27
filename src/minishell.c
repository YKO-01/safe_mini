/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:33:01 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/27 21:58:43 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	clear_lst(t_list *lst)
{
	t_list	*cur;
	
	while (lst)
	{
		cur  = lst;
		lst = lst->next;
		free(cur);
	}
}

void	minishell(void)
{
	char	*line;
	t_list	*lst;

	lst = NULL;
    sleep(1);
	while (1)
	{
		line = display_prompt();
		check_input(line);
		loop_on_input(line, &lst);
		t_list *t = lst;
		while (t)
		{
			printf("-----------------------------\n");
			printf("t->content = %s\n", t->data->content);
			printf("t->state = %d\n", t->data->state);
			printf("t->token = %d\n", t->data->token);
			t = t->next;
		}
		// exit(0);
		check_type_cmd(lst);
		free(line);
		clear_lst(lst);
		lst  = 0;
	}
}
