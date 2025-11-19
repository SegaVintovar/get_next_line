/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   NEWNEW.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/19 20:04:49 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/19 20:09:07 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static char *buffer = NULL;
	char		*tmp[BUFFER_SIZE + 1];
	int			bytes = 1;
	char 		*line;
	
	if (buffer != NULL)
		//copy from the buffer into the line
		//check for the \n
	
	
	
}