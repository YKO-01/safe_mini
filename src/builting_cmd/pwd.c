/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:59:04 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/23 13:42:58 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_pwd()
{
    char pwd[PATH_MAX];
    char *path;

    if (getcwd(pwd, sizeof(pwd)))
        printf("%s\n", pwd);;
}