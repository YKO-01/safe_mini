/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:53:55 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/05/27 18:55:27 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
//# include "minishell.h"

typedef enum e_state
{
	IN_SQ = 1,
	IN_DQ,
	NOTHING
}	t_state;

typedef enum e_token
{
	WORD = 1,
	ENV,
	WHITE_SPACE,
	SINGLE_Q,
	DOUBLE_Q,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC
}	t_token;

typedef struct s_data
{
	char	*content;
	t_state 	state;
	t_token	token;
}	t_data;

typedef struct s_list
{
	t_data			*data;
	struct s_list	*next;
}	t_list;

void	loop_on_input(char *line, t_list **lst);
void	if_string(char *line, t_list **lst, int *pos);
void	if_space(char *line, t_list **lst);
char	*handle_quote(t_list **lst, char *line, int *pos, int ascii);
void	if_single_quote(char *line, t_list **lst, int *pos);
void	if_double_quote(char *line, t_list **lst, int *pos);
void	input_redirection(char *line, t_list **lst, int *pos);
void	output_redirection(char *line, t_list **lst, int *pos);
void	if_dollar_sign(char *line, t_list **lst, int *pos);
void	if_pipe(char *line, t_list **lst, int *pos);
void	other_characters(char *line, t_list **lst, int *pos);

#endif
