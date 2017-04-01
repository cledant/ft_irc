/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:40:45 by cledant           #+#    #+#             */
/*   Updated: 2017/04/01 18:07:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int		main(int argc, char **argv)
{
	t_clnt_env		env;
	t_err			err;

	ft_bzero(&env, sizeof(t_clnt_env));
	if (argc == 1)
	{
		if ((err = clnt_connect_server(DEFAULT_IP, DEFAULT_PORT, env))
				!= ERR_NONE)
			return (print_error(err, str));
	}
	else if (argc == 2)
	{
		if ((err = clnt_connect_server(argv[1], argv[2], env))
				!= ERR_NONE)
			return (print_error(err, str));
	}
	else if (argc == 2)
	{
		if ((err = clnt_connect_server(argv[1], argv[2], env))
				!= ERR_NONE)
			return (print_error(err, str));
	}
	return (0);
}
