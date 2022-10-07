/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:53:44 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/10/07 06:00:05 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int
	ft_putchar(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(char)) != sizeof(char))
		return (-1);
	return (1);
}
