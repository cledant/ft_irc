/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:44:43 by cledant           #+#    #+#             */
/*   Updated: 2017/04/17 14:18:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_read(t_cbuff *cbuff_read, int fd_sock)
{
	int		rvd;

	if ((rvd = recv(fd_sock, cbuff_read->enqueue_buff, CBUFF_SIZE, 0)) <= 0)
	{
		//deco a faire
		return ;
	}
	cbuff_enqueue(cbuff_read, rvd);
}
