/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:24:50 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/17 18:28:38 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../library/libft/inc/libft.h"
# include "../library/ft_printf/inc/ft_printf.h"
# include "../library/ft_gnl/inc/libgnl.h"

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

// Minitalk Utils
void	ft_error_handler(int i);
int		ft_str_isdigit(char *str);
void	ft_handler(int sig);

#endif
