/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:00:33 by cledant           #+#    #+#             */
/*   Updated: 2017/04/19 18:26:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_execute_cmd(t_env *env, t_cmd *cmd)
{
	if (cmd->target == ONE_TIME_TO_USER_WITH_COMMON_CHAN)
		srv_com_one_time_common_chan(env, cmd);
	else if (cmd->target == TARGET_SENDER)
		srv_com_send_to_sender(env, cmd);
	else if (cmd->target == TARGET_USER)
		srv_com_send_to_user(env, cmd);
	else if (cmd->target == TARGET_USER_AND_SENDER)
	{
		srv_com_send_to_user(env, cmd);
		srv_com_send_to_sender(env, cmd);
	}
	else if (cmd->target == TARGET_CHAN)
		srv_com_send_to_target_chan(env, cmd);
	else if (cmd->target == TARGET_CHAN_AND_SENDER)
		srv_com_send_to_target_chan_and_sender(env, cmd);
}
