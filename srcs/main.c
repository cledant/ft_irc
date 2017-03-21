/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:09:50 by cledant           #+#    #+#             */
/*   Updated: 2017/03/21 16:04:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static int		print_err(const t_err code, const char *str)	
{
	if (code == ERR_NB_ARG)
		printf("Usage : %s <port>\n", str);
	else if (code == ERR_ARG_NOT_INIT)
		printf("%s : Invalid port\n");
	else if (code == ERR_GET_RLIM)
		printf("%s : Error getting system limits\n");
	else if (code == ERR_MAX_FD)
		printf("%s : Invalid max fd\n");
	else if (code == ERR_ALLOC_MEM)
		printf("%s : Can't allocate memory\n");
	return (-1);
}

int				main(int argc, char **argv)
{
	t_env	env;
	t_err	err;

	if (argc != 2)
		return (print_err(ERR_NB_ARG, argv[0]));
	if ((err = irc_init_env(&env, argv)) != ERR_NONE)
		return (print_err(err, argv[0]));
	if ((err = irc_create_server(&env)) != ERR_NONE)
		return (print_err(err, argv[0]));
	return (0);
}
