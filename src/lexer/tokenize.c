/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:44:57 by osajide           #+#    #+#             */
/*   Updated: 2023/05/27 22:13:01 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>

char	*ft_remove_char(char *s)
{
	char	*new_char;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			j++;
		i++;
	}
	new_char = malloc((i - j) + 1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			i++;
		else
			new_char[j++] = s[i++];
	}
	new_char[j] = '\0';
	free(s);
	return (new_char);
}

char	*handle_quote(t_list **lst, char *line, int *pos, int ascii)
{
	char	*temp;
	int		start;

	(*pos)++;
	start = *pos;
	while (line[*pos] && line[*pos] != ascii)
		(*pos)++;
	temp = ft_substr(line, start, *pos);
	return (temp);
}

// ls -la || ls-la handled

void	if_string(char *line, t_list **lst, int *pos)
{
	int		start;
	int		ascii;
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	start = *pos;
	while (line[*pos] && line[*pos] != '$' && line[*pos] != '|' && line[*pos] != '<' && line[*pos] != '>' && line[*pos] != ' ')
		(*pos)++;
	temp = ft_substr(line, start, *pos);
	temp = ft_remove_char(temp);
	ft_lstadd_back(lst, ft_lstnew(temp, NOTHING, WORD));
	if (line[*pos] != ' ' && line[*pos] != '$')
	{
		start = *pos;
		while (line[*pos] && (line[*pos] == '|' || line[*pos] == '>' || line[*pos] == '<' || line[*pos] == '$'))
			(*pos)++;
		temp2 = ft_substr(line, start, *pos);
		if (temp2 && *temp2)
			ft_lstadd_back(lst, ft_lstnew(temp2, NOTHING, PIPE)); // need to handle token in different cases
	}
	(*pos)--;
}

void	if_single_quote(char *line, t_list **lst, int *pos)
{
	char	*temp;
	char	*temp2;
	int		start;

	temp = NULL;
	temp2 = NULL;
	temp = handle_quote(lst, line, pos, 39);
	(*pos)++;
	start = *pos;
	while (line[*pos] && line[*pos]!= '$' && line[*pos] != '|' && line[*pos] != '<' && line[*pos] != '>' && line[*pos] != ' ')
		(*pos)++;
	temp2 = ft_strjoin(temp, ft_substr(line, start, *pos));
	if (temp2 && *temp2)
		ft_lstadd_back(lst, ft_lstnew(ft_remove_char(temp2), NOTHING, WORD));
}

void	if_double_quote(char *line, t_list **lst, int *pos)
{
	char	*temp;
	char	*temp2;
	char	*temp3;
	int		start;

	temp = NULL;
	(*pos)++;
	start = *pos;
	while (line[*pos] && line[*pos] != 34)
		(*pos)++;
	temp = ft_substr(line, start, *pos);
	if (line[*pos])
	{(*pos)++;
	start = *pos;
	while (line[*pos] && line[*pos]!= '$' && line[*pos] != '|' && line[*pos] != '<' && line[*pos] != '>' && line[*pos] != ' ')
		(*pos)++;
	temp2 = ft_substr(line, start, *pos);
	temp3 = ft_strjoin(temp, temp2);
	if (temp3 && *temp3)
		ft_lstadd_back(lst, ft_lstnew(ft_remove_char(temp3), NOTHING, WORD));}
	else
		ft_lstadd_back(lst, ft_lstnew(temp, IN_DQ, WORD));
}
