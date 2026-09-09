/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:29:04 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/09 20:07:02 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	bench_checker(int *argc, char **argv)
{
	int i;

	i = 1;
	while (i < *argc)
	{
		if (ft_strncmp((argv)[i], "--bench", 8) == 0)
			return (1);
		i++;
	}
	return (0);
}
