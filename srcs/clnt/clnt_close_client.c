/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_close_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:09:20 by cledant           #+#    #+#             */
/*   Updated: 2017/04/18 13:15:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		clnt_close_client(void)
{
	t_clnt_env		*env;

	if ((env = clnt_get_env(NULL)) != NULL)
	{
		clnt_disconnect(env);
		clnt_close_ncurses(env);
		clnt_destroy_env(env);
	}
	printf("%s : Closed !\n", env->file_name);
	exit(0);
}
