/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_dollar_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:41:17 by osajide           #+#    #+#             */
/*   Updated: 2023/05/27 18:54:23 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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