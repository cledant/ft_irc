/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_create_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:17:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 14:06:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				error_advance_head(t_fd *fd, const size_t size)
{
	cbuff_move_forward_read_head(fd->cbuff_read, size);
	return (0);
}

static inline int		finish_cmd(t_cmd *cmd, const char *begin,
							const char *end, const int fd_sock)
{
	if (cmd->function == NICK)
		return (srv_cmd_nick(cmd, begin, end, fd_sock));
//	if (cmd->function == JOIN)
//		return (srv_cmd_join(cmd, begin, end, fd_sock));
	ft_puts("Unknown command !");
	return (0);
}

static inline int		get_cmd(const int fd_sock, const char *begin,
							const char *end, t_cmd *cmd)
{
	size_t	size;
	char	*space;
	char	*cmd_str;

	if ((size = end - begin - 1) == 0 || (size = end - begin - 1) >
			MAX_PACKET_SIZE || ft_isspace(*(begin + 1)) == 1)
		return (0);
	if ((space = ft_strnstr(begin, " ", size)) == NULL)
		return (0);
	if ((cmd_str = ft_strnew(space - 1 - begin + 1)) == NULL)
	{
		ft_puts("Memory allocation error");
		return (0);
	}
	ft_memcpy(cmd_str, begin + 1, space - 1 - begin + 1);
	if (srv_is_cmd_valid(cmd_str, cmd) == 0)
	{
		free(cmd_str);
		return (0);
	}
	finish_cmd(cmd, begin, end, fd_sock);
	free(cmd_str);
	return (1);
}

int						srv_create_cmd(t_env *env, const int fd_sock,
							t_cmd *cmd)
{
	char	*begin;
	char	*end;

	cbuff_dequeue_till_head_no_change(env->list_fd[fd_sock].cbuff_read);
	if ((begin = ft_strnstr(env->list_fd[fd_sock].cbuff_read->dequeue_buff,
			BEGIN_PACKET, CBUFF_SIZE)) == NULL)
		return (0);
	if ((end = ft_strnstr(env->list_fd[fd_sock].cbuff_read->dequeue_buff,
			END_PACKET, CBUFF_SIZE)) == NULL)
		return (0);
	if (begin > end)
	{
		if ((end = ft_strnstr(begin, END_PACKET, CBUFF_SIZE)) == NULL)
			return (error_advance_head(&(env->list_fd[fd_sock]),
				env->list_fd[fd_sock].cbuff_read->dequeue_buff - begin));
	}
	if (get_cmd(fd_sock, begin, end, cmd) == 0)
		return (error_advance_head(&(env->list_fd[fd_sock]),
			env->list_fd[fd_sock].cbuff_read->dequeue_buff - end +
			ft_strlen(END_PACKET) - 1));
	cbuff_move_forward_read_head(env->list_fd[fd_sock].cbuff_read,
			env->list_fd[fd_sock].cbuff_read->dequeue_buff - end +
			ft_strlen(END_PACKET) - 1);
	return (1);
}
