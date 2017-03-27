/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_create_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:17:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/27 22:16:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int				error_advance_head(t_fd *fd, const size_t size)
{
	cbuff_move_forward_read_head(fd->cbuff_read, size);
	return (0);
}

static int				free_error_advance_head(t_fd *fd, const size_t size,
							char *str)
{
	free(str);
	cbuff_move_forward_read_head(fd->cbuff_read, size);
	return (0);
}

static inline int		finish_cmd(t_cmd *cmd, char *begin, char *end)
{
	if (cmd->function == NICK)
		return (srv_cmd_nick(cmd, begin, end));
	if (cmd->function == JOIN)
		return (srv_cmd_join(cmd, begin, end));
	ft_puts("Unknown command !");
	return (0);
}

static inline int		get_cmd(t_fd *fd, const char *begin, const char *end,
							t_cmd *cmd)
{
	size_t	size;
	size_t	cmd_size;
	char	*space;
	char	*cmd_str;

	if ((size = end - begin - 1) == 0 || (size = end - begin - 1) >
			MAX_PACKET_SIZE || ft_isspace(*(begin + 1)) == 1)
		return (error_advance_head(fd, size + ft_strlen(END_PACKET)));
	if ((space = ft_strnstr(begin, " ", size)) == NULL)
		return (error_advance_head(fd, size + ft_strlen(END_PACKET)));
	if ((cmd_str = ft_strnew(space - 1 - begin + 1)) == NULL)
	{
		ft_puts("Memory allocation error");
		return (0);
	}
	ft_memcpy(cmd_str, begin + 1, cmd_size);
	if (srv_is_cmd_valid(cmd_str, cmd) == 0)
		return (free_error_advance_head(fd, size + ft_strlen(END_PACKET),
			cmd_str));
	if (finish_cmd(cmd_str, cmd) == 0)
		return (free_error_advance_head(fd, size + ft_strlen(END_PACKET),
			cmd_str));
	free(cmd_str);
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
				env->list_fd[fd_sock].cbuff_read->dequeue_buff - begin - 1));
		}
	}
	if (get_cmd(&(env->list_fd[fd_stock]), begin, end, cmd) == 0)
		return (0);
	cmd->fd_sender = fd_sock;
	cbuff_move_forward_read_head(env->list_fd[fd_sock].cbuff_read,
		end - begin + ft_strlen(END_PACKET) - 1);
	return (1);
}
