/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_seek_userlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 10:50:58 by cledant           #+#    #+#             */
/*   Updated: 2017/04/01 12:00:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline void		get_nb_user_in_chan(t_env *env, t_userlist *u_list)
{
	int		c;

	c = 0;
	while (c < env->max_fd)
	{
		if (env->list_fd[c].joined_chan[u_list->chan_id] == IN_CHAN)
			(u_list->nb_user)++;
		c++;
	}
}

void					srv_seek_userlist(t_env *env, t_userlist *u_list)
{
	int			c;
	size_t		len_buffer;
	size_t		len_user;

	c = 0;
	get_nb_user_in_chan(env, u_list);
	srv_itoa_buffer(u_list->nb_user, u_list->user_list);
	if (u_list->nb_user == 0)
		return ;
	while (c < env->max_fd)
	{
		if (env->list_fd[c].joined_chan[u_list->chan_id] == IN_CHAN)
		{
			len_buffer = ft_strlen(u_list->user_list);
			len_user = ft_strlen(env->list_fd[c].nick);
			if (len_buffer + len_user + 1 < MAX_MSG_LEN + 1)
			{
				ft_strcat(u_list->user_list, " ");
				ft_strcat(u_list->user_list, env->list_fd[c].nick);
			}
		}
		c++;
	}
}
