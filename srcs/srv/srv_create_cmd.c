/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_create_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:17:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/27 19:19:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				error_advance_head(t_fd *fd, const size_t size)
{
	cbuff_move_forward_read_head(fd->cbuff_read, size);
	return (0);
}

static inline int		get_cmd(t_fd *fd, const char *begin, const char *end,
							t_cmd *cmd)
{
	size_t	size;
	size_t	cmd_size;
	char	*space;
	char	*cmd_str;

	if ((size = end - begin) == 0 || (size = end - begin) > MAX_PACKET_SIZE ||
			ft_isspace(*begin) == 1)
		return (error_advance_head(fd, size + ft_strlen(END_PACKET)));
	if ((space = ft_strnstr(begin, " ", size)) == NULL)
		return (error_advance_head(fd, size + ft_strlen(END_PACKET)));
	if ((cmd_str = ft_strnew(space - begin - 1)) == NULL)
	{
		ft_puts("Memory allocation error");
		return (0);
	}
	ft_memcpy(cmd_str, begim, cmd_size);
	if (srv_is_cmd_valid(cmd_str) == 0)
		return (error_advance_head(fd, size + ft_strlen(END_PACKET)));
	if (concat_cmd(cmd_str, cmd) == 0)
		return (error_advance_head(fd, size + ft_strlen(END_PACKET)));
	return (1);
}

int		srv_create_cmd(t_env *env, const int fd_sock, t_cmd *cmd)
{
	char	*begin;
	char	*end;

	cbuff_dequeue_till_head_no_change(%(env->list_fd[fd_sock].cbuff_read));
	if ((begin = ft_strnchr(env->list_fd[fd_sock].cbuff_read->dequeue_buff,
			BEGIN_PACKET, CBUFF_SIZE)) == NULL)
		return (0);
	if ((end = ft_strnchr(env->list_fd[fd_sock].cbuff_read->dequeue_buff,
			END_PACKET, CBUFF_SIZE)) == NULL)
		return (0);
	if (begin > end)
	{
		if ((end = ft_strnchr(begin, END_PACKET, CBUFF_SIZE)) == NULL)
		{
			return (error_advance_head(&(env->list_fd[fd_sock]),
				env->list_fd[fd_sock].cbuff_read - begin));
		}
	}
	if (get_cmd(&(env->list_fd[fd_stock]), begin, end, cmd) == 0)
		return (0);
	cbuff_move_forward_read_head(env->list_fd[fd_sock].cbuff_read,
		end - begin + ft_strlen(END_PACKET));
	return (1);
}
