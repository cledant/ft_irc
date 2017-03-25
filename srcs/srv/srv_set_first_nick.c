/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_set_first_nick.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:52:35 by cledant           #+#    #+#             */
/*   Updated: 2017/03/25 18:51:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		srv_set_first_nick(t_env *env, int fd_sock)
{
	int				nb;
	static char		*prefix = "U_";
	char			*str;

	nb = 0;
	while (nb < 10000)
	{
		if ((str = ft_itoa(nb)) == NULL)
			return (0);
		ft_strcat(env->list_fd[fd_sock].nick, prefix);
		ft_strcat(env->list_fd[fd_sock].nick, str);
		if ((srv_is_nick_free(env, fd_sock, env->list_fd[fd_sock].nick)) == 1)
		{
			free(str);
			return (1);
		}
		free(str);
		ft_bzero(env->list_fd[fd_sock].nick, MAX_NICK_LEN + 1);
		nb++;
	}
	return (0);
}
