/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:25:38 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/08 19:42:52 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long			i;
	unsigned int	minuses;

	i = 0;
	minuses = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			minuses++;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		i = i * 10;
		i = i + (*str - 48);
		str++;
	}
	if (minuses > 0)
		i = i * -1;
	return ((int) i);
}
