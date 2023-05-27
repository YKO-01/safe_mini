/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:50:25 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/25 16:25:51 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_CMD_H
# define BUILTIN_CMD_H

# include "minishell.h"

/************* BUILIN COMMAND ************/

void	ft_echo(t_list *list);
void    ft_pwd();

/************** BUILTIN UTILS ************/

char *join_with_free(char *str, char *buff);

#endif