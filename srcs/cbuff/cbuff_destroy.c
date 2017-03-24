/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuff_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:34:43 by cledant           #+#    #+#             */
/*   Updated: 2017/03/24 14:36:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		cbuff_destroy(t_cbuff **cbuff)
{
	free((*cbuff)->buff);
	free((*cbuff)->enqueue_buff);
	free((*cbuff)->dequeue_buff);
	free(*cbuff);
	*cbuff = NULL;
}
