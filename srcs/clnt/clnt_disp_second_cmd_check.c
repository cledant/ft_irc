/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clnt_disp_second_cmd_check.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:50:56 by cledant           #+#    #+#             */
/*   Updated: 2017/04/20 13:45:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

static inline int		is_welcome_cmd(const char *cmd_part, t_disp_cmd *cmd)
{
	if (ft_strcmp(cmd_part, "WELCOME") != 0)
		return (0);
	cmd->function = WELCOME;
	return (1);
}

int		clnt_disp_second_cmd_check(t_disp_cmd *cmd, const t_cmd_arg *arg)
{
	char	*ptr_space_one;
	char	*ptr_space_two;
	char	cmd_part[MAX_CMD_SIZE + 1];
	size_t	len;

	if ((ptr_space_one = ft_strnstr(arg->begin, " ",
			arg->end - arg->begin - 1)) == NULL)
		return (0);
	if ((len = arg->end - ptr_space_one - 1) == 0)
		return (0);
	if ((ptr_space_two = ft_strnstr(ptr_space_one + 1, " ",
			arg->end - ptr_space_one)) == NULL)
		return (0);
	ft_bzero(&cmd_part, MAX_CMD_SIZE + 1);
	if (ptr_space_two == NULL)
	{
		ft_memcpy(&cmd_part, ptr_space_one + 1, len - 1);
		if (is_welcome_cmd(cmd_part, cmd) == 0)
			return (0);
	}
/*	else
	{
		if ((len = ptr_space_two - ptr_space_one - 1) == 0)
			return (0);
		ft_memcpy(&cmd_part, ptr_space_one + 1, len);
		//a voire;
	}*/
	return (1);
}
