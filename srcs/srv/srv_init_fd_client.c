/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_fd_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:34:54 by cledant           #+#    #+#             */
/*   Updated: 2017/03/23 16:15:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_init_fd_client(t_fd *fd)
{
	fd->type = FD_CLIENT;
	fd->fct_read = srv_client_read;
	fd->fct_write = srv_client_write;
	ft_bzero(fd->buff_read, IRC_BUFF_SIZE + 1);
	ft_bzero(fd->buff_write, IRC_BUFF_SIZE + 1);
}
