/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 12:00:33 by cledant           #+#    #+#             */
/*   Updated: 2017/03/29 18:25:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void		srv_execute_cmd(t_env *env, t_cmd *cmd)
{
	if (cmd->target == ONE_TIME_TO_USER_WITH_COMMON_CHAN)
		srv_com_one_time_common_chan(env, cmd);
	else if (cmd->target == TARGET_SENDER)
		srv_com_send_to_sender(env, cmd);
	else if (cmd->target == TARGET_CHAN)
		srv_com_send_to_target_chan(env, cmd);
}
