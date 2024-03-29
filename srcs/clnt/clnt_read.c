/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:44:43 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 16:36:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_read(t_cbuff *cbuff_read, int fd_sock, t_clnt_env *env)
{
	int		rvd;

	if ((rvd = recv(fd_sock, cbuff_read->enqueue_buff, CBUFF_SIZE, 0)) <= 0)
	{
		clnt_disconnect(env);
		return ;
	}
	cbuff_enqueue(cbuff_read, rvd);
}
