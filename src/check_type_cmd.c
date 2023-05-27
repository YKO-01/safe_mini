/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:44:16 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/27 22:01:12 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void check_type_cmd(t_list *lst)
{
    if (!ft_strncmp(lst->data->content, "pwd", ft_strlen(lst->data->content)))
        ft_pwd();
    else if (!ft_strncmp(lst->data->content, "echo", ft_strlen(lst->data->content)))
        ft_echo(lst);
}