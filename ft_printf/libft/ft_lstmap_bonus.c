/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:23:45 by cpeset-c          #+#    #+#             */
/*   Updated: 2022/05/27 11:16:08 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elt;
	t_list	*temp;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		new_elt = ft_lstnew(temp);
		if (!new_elt)
		{
			del(temp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elt);
		lst = lst->next;
	}
	return (new_lst);
}

/*										*/
/*	La función lstmap hace varías cosas. Recorre la lista, creamos una	*/
/*	nueva lista pasando el contenido de la función recibida como param	*/
/*	metro y en caso de que falle la alojación de memoria creando la 	*/
/*	lista la vaciamos y liberamos la memoria alojada. Por último devuel-	*/
/*	vo la lista creada.							*/
/*										*/
