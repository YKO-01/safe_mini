/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:01:48 by osajide           #+#    #+#             */
/*   Updated: 2023/05/27 21:27:38 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	input_redirection(char *line, t_list **lst, int *pos)
{
	char	*temp;

	temp = NULL;
	if (line[*pos + 1] == '>')
	{
		temp = ft_substr(line, *pos, *pos + 2);
		ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, REDIR_OUT));
		(*pos)++;
	}
	else
	{
		temp = ft_strjoin(temp , ">");
		ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, REDIR_OUT));
	}
}

void	output_redirection(char *line, t_list **lst, int *pos)
{
	char	*temp;
	
	temp = NULL;
	if (line[*pos + 1] == '>')
	{
		temp = ft_substr(line, *pos, *pos + 2);
		ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, REDIR_OUT));
		(*pos)++;
	}
	else
	{
		temp = ft_strjoin(temp , ">");
		ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, REDIR_OUT));
	}
}

void	other_characters(char *line, t_list **lst, int *pos)
{
	char	*temp;
	int		start;

	temp = NULL;
	start = *pos;
	while (line[*pos] && line[*pos] != 32)
		(*pos)++;
	temp = ft_substr(line, start, *pos);
	ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, WORD));
}