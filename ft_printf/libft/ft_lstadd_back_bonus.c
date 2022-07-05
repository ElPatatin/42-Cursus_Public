/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:21:04 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/27 11:18:25 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

/*										*/
/*	La función lstadd_back añade el nodo new al final de la lista. La	*/
/*	función trabaja de forma recursiva. Si la lista no esta al final	*/
/*	vuelve ha pasar la función pero con el siguiente valor de la lista.	*/
/*										*/
