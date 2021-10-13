/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:59:07 by jlong             #+#    #+#             */
/*   Updated: 2021/10/13 10:03:12 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*content;
	t_list	*next_content;

	content = *lst;
	if (lst)
	{
		while (content)
		{
			next_content = content ->next;
			ft_lstdelone(content, (del));
			content = next_content;
		}
		*lst = NULL;
	}
}
