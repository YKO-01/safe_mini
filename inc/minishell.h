/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:18:34 by osajide           #+#    #+#             */
/*   Updated: 2023/05/27 12:12:49 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include "../libft/libft.h"
//# include <readline/hestory.h>
# include "builtin_cmd.h"
# include "lexer.h"
# include "parser.h"
// typedef enum state
// {
// 	IN_SQ = 1,
// 	IN_DQ = 2,
	
// }	state;

// typedef struct s_data
// {
// 	char	*content;
// 	state 	state;
// 	int		type;
// }	t_data;

/************ init *****************/
void	welcoming_msg(void);

/************ prompt ***************/

char	*display_prompt(void);

/* ========== handling_input ========= */

void	check_input(char *line);
int		check_quotes(char *str);
int		check_pipes(char *str, char c);

/************ main function ********/

void	minishell(void);
;
/************ CHECK TYPE COMMAND *************/

void check_type_cmd(t_list *lst);

#endif
