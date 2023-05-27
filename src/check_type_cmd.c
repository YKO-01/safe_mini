/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:44:16 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/25 17:41:23 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_type_cmd(t_list *lst)
{
    if (!ft_strncmp(lst->data->content, "pwd", ft_strlen(lst->data->content)))
        ft_pwd();
    else if (!ft_strncmp(lst->data->content, "echo", ft_strlen(lst->data->content)))
        ft_echo(lst);
}