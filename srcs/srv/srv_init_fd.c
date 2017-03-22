/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_init_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:43:11 by cledant           #+#    #+#             */
/*   Updated: 2017/03/22 14:17:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_init_fd_free(t_fd *fd)
{
	fd->type = FD_FREE;
	fd->fct_read = NULL;
	fd->ft_write = NULL;
	ft_bzero(fd->buff_read, IRC_BUFF_SIZE + 1);
	ft_bzero(fd->buff_write, IRC_BUFF_SIZE + 1);
}
