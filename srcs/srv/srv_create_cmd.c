/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_create_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:17:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 15:40:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int		error_advance_head(t_fd *fd, const size_t size)
{
	cbuff_move_forward_read_head(fd->cbuff_read, size);
	return (0);
}

static inline int		finish_cmd(t_cmd *cmd, const t_cmd_arg *arg,
							t_env *env, const int fd_sock)
{
	if (cmd->function == NICK)
		return (srv_cmd_nick(cmd, arg, env, fd_sock));
	if (cmd->function == JOIN)
		return (srv_cmd_join(cmd, arg, env, fd_sock));
	ft_puts("Unknown command !");
	return (0);
}

static inline int		get_cmd(const int fd_sock, const t_cmd_arg *arg,
							t_cmd *cmd, t_env *env)
{
	size_t	size;
	char	*space;
	char	cmd_str[MAX_PACKET_SIZE + 1];

	size = arg->end - arg->begin - 1;
	if (size == 0 || size > MAX_PACKET_SIZE || ft_isspace(*(arg->begin + 1))
			== 1)
		return (0);
	if ((space = ft_strnstr(arg->begin, " ", size)) == NULL)
		return (0);
	ft_bzero(cmd_str, MAX_PACKET_SIZE + 1);
	ft_memcpy(cmd_str, arg->begin + 1, space - 1 - arg->begin);
	if (srv_is_cmd_valid(cmd_str, cmd) == 0)
		return (0);
	finish_cmd(cmd, arg, env, fd_sock);
	return (1);
}

int						srv_create_cmd(t_env *env, const int fd_sock,
							t_cmd *cmd)
{
	t_cmd_arg		arg;

	cbuff_dequeue_till_head_no_change(env->list_fd[fd_sock].cbuff_read);
	if ((arg.begin = ft_strnstr(env->list_fd[fd_sock].cbuff_read->dequeue_buff,
			BEGIN_PACKET, CBUFF_SIZE)) == NULL)
		return (0);
	if ((arg.end = ft_strnstr(env->list_fd[fd_sock].cbuff_read->dequeue_buff,
			END_PACKET, CBUFF_SIZE)) == NULL)
		return (0);
	if (arg.begin > arg.end)
	{
		if ((arg.end = ft_strnstr(arg.begin, END_PACKET, CBUFF_SIZE)) == NULL)
			return (error_advance_head(&(env->list_fd[fd_sock]),
				env->list_fd[fd_sock].cbuff_read->dequeue_buff - arg.begin));
	}
	if (get_cmd(fd_sock, &arg, cmd, env) == 0)
		return (error_advance_head(&(env->list_fd[fd_sock]),
			env->list_fd[fd_sock].cbuff_read->dequeue_buff - arg.end +
			ft_strlen(END_PACKET) - 1));
	cbuff_move_forward_read_head(env->list_fd[fd_sock].cbuff_read,
			env->list_fd[fd_sock].cbuff_read->dequeue_buff - arg.end +
			ft_strlen(END_PACKET) - 1);
	return (1);
}
