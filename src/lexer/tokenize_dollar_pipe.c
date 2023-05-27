/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_dollar_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:41:17 by osajide           #+#    #+#             */
/*   Updated: 2023/05/27 21:27:25 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	if_dollar_sign(char *line, t_list **lst, int *pos)
{
	int		start;
	char	*temp;
	
	start = *pos;
	temp = NULL;
	(*pos)++;
	while (line[*pos] && ((line[*pos] >= 'a' && line[*pos] <= 'z') || (line[*pos] >= 'A' && line[*pos] <= 'Z') || (line[*pos] >= '0' && line[*pos] <= '9')))
		(*pos)++;
	temp = ft_substr(line, start, *pos);
	ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, ENV));
	(*pos)--;
}

void	if_pipe(char *line, t_list **lst, int *pos)
{
	char	*temp;

	temp = NULL;
	temp = ft_strjoin(temp , "|");
	ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, PIPE));
}