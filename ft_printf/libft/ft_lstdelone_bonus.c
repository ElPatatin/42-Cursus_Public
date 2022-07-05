/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:22:25 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/27 11:07:15 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del (lst->content);
	free (lst);
}

/*										*/
/*	La función lstdelone libera el contenido de la lista. Primero asig-	*/
/*	no un valor vacio a la lista y luego liberamos la memoría.		*/
/*										*/
