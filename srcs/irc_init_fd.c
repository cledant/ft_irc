/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_init_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:43:11 by cledant           #+#    #+#             */
/*   Updated: 2017/03/21 15:48:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		irc_init_fd(t_fd *fd)
{
	fd->type = IRC_FREE;
	ft_bzero(fd->buff_read, IRC_BUFF_SIZE + 1);
	ft_bzero(fd->buff_write, IRC_BUFF_SIZE + 1);
}
