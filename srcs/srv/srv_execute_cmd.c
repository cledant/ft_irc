/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:00:33 by cledant           #+#    #+#             */
/*   Updated: 2017/03/28 14:08:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_execute_cmd(t_env *env, t_cmd *cmd)
{
	if (cmd->target == ONE_TIME_TO_USER_WITH_COMMON_CHAN)
		srv_com_one_time_common_chan(env, cmd);
}
