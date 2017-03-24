/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuff_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:18:24 by cledant           #+#    #+#             */
/*   Updated: 2017/03/24 15:48:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

t_cbuff		*clean_fail(void *base, void *buff_1, void *buff_2, void *buff_3)
{
	if (buff_1 != NULL)
		free(buff_1);
	if (buff_2 != NULL)
		free(buff_2);
	if (buff_3 != NULL)
		free(buff_3);
	if (base != NULL)
		free(base);
	return (NULL);
}

t_cbuff		*cbuff_create(const size_t buff_size)
{
	t_cbuff		*new_cbuff;

	if (buff_size == 0)
		return (NULL);
	if ((new_cbuff = (t_cbuff *)malloc(sizeof(t_cbuff))) == NULL)
		return (NULL);
	if ((new_cbuff->buff = (char *)malloc(sizeof(char) * buff_size)) == NULL)
		return (clean_fail(new_cbuff, new_cbuff->buff, NULL, NULL));
	if ((new_cbuff->enqueue_buff = (char *)malloc(sizeof(char) * buff_size + 1))
			== NULL)
		return (clean_fail(new_cbuff, new_cbuff->buff, new_cbuff->enqueue_buff,
					NULL));
	if ((new_cbuff->dequeue_buff = (char *)malloc(sizeof(char) * buff_size + 1))
			== NULL)
		return (clean_fail(new_cbuff, new_cbuff->buff, new_cbuff->enqueue_buff,
					new_cbuff->dequeue_buff));
	new_cbuff->r_pos = 0;
	new_cbuff->w_pos = 0;
	new_cbuff->overwrite = 0;
	new_cbuff->size = buff_size;
	return (new_cbuff);
}
