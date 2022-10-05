/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:53:44 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/08/27 19:30:31 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putchar(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (1);
}
