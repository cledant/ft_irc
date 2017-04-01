/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_shutdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:15:05 by cledant           #+#    #+#             */
/*   Updated: 2017/04/01 14:38:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_shutdown(void)
{
	t_env		*env;

	if ((env = srv_get_env(NULL)) != NULL)
	{
		srv_close_all_client_socket(env);
		srv_close_srv_socket(env);
		if (env->new_data != NULL)
			free(env->new_data);
		srv_destroy_fd(env);
	}
	printf("%s : Shutdown !\n", env->file_name);
	exit(0);
}
