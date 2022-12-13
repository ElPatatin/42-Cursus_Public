/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:24:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/12/13 19:27:25 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_printf_fd.h"

// Error Codes
# define ERRCODE0	(int)0
# define ERRCODE1	(int)1
# define ERRCODE2	(int)2
# define ERRCODE3	(int)3
# define ERRCODE4	(int)4
# define ERRCODE5	(int)5

// Error Messages
# define ERR_MSG	(char *)"\aError!\n"
# define ERR_MSG1	(char *)"\aError! Invalid parameters given!\n"
# define ERR_MSG2	(char *)"\aError! Invalid PID!\n"
// Unsused
# define ERR_MSG3	(char *)"\aError! Invalid message!\n"
# define ERR_MSG4	(char *)"\aSomething went wrong while generating PID!\n"
// Pending to be implemented
# define ERR_MSG5	(char *)"\aSomething went wrong with comms from server!\n"

# define CYAN		(char *)"\033[1;36m"
# define RED		(char *)"\033[1;31m"
# define END		(char *)"\033[0;39m"

// Minitalk Utils
void	error_buffer(char **str);
void	error_handler(int err);
int		ft_str_isdigit(char *str);
void	ft_handler(int sig);

#endif
