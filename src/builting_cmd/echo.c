/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:13:36 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/27 22:02:20 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
