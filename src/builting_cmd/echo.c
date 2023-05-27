/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:13:36 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/27 18:56:44 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *join_with_free(char *str, char *buff)
{
	char *tmp;
	tmp = ft_strjoin(str, buff);
	if (!tmp)
		return (NULL);
	free(str);
	return tmp;
}

void	ft_echo(t_list *lst)
{
	char	*line;
	int		i;

	i = 0;
	lst = lst->next;
	
	if (lst && !ft_strncmp(lst->data->content, "-n", ft_strlen(lst->data->content)))
	{
		i = 1;
		lst = lst->next;
	}
	while (lst && lst->data->token == 1)
	{
		line = lst->data->content;
		if (lst->next || lst->data->token == 1)
			line = join_with_free(line, " ");
		printf("%s", line);
		lst = lst->next;
	}
	if(i == 0)
		printf("\n");
}
