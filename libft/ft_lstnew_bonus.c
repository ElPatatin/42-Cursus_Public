/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:17:10 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/19 15:00:48 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

/*										*/
/*	La función lstnew crea una nueva lista. Alocamos la memoría necesaría	*/
/*	para la nueva lista. Asignamos el contenido a la lista y asignamos	*/
/*	el final de la lista. Finalmente devolvemos la lista creada.		*/
/*										*/
