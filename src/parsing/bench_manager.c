/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 18:29:04 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/11 20:48:52 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	put_metric(char *label, int value)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(value, 2);
}

static void print_strat_name(t_strategy strat, double dis)
{
    ft_putstr_fd("[bench] strategy: ", 2);
    if (strat == SIMPLE)
        ft_putstr_fd("Simple / O(n^2)\n", 2);
    else if (strat == MEDIUM)
        ft_putstr_fd("Medium / O(n√n)\n", 2);
    else if (strat == COMPLEX)
        ft_putstr_fd("Complex / O(n log n)\n", 2);
    else
    {
        if (dis < 0.2)
            ft_putstr_fd("Adaptive / O(n^2)\n", 2);
        else if (dis < 0.5)
            ft_putstr_fd("Adaptive / O(n√n)\n", 2);
        else
            ft_putstr_fd("Adaptive / O(n log n)\n", 2);
    }
}

static void print_header(double dis, t_strategy strat)
{
    int     dec;
    double  percent;

    percent = dis * 100.0; 
    put_metric("[bench] disorder: ", (int)percent);
    ft_putstr_fd(".", 2);
    dec = (int)(((percent - (double)((int)percent)) * 100) + 0.5);
    if (dec < 10)
        ft_putstr_fd("0", 2);
    put_metric("", dec);
    ft_putstr_fd("%\n", 2);
    print_strat_name(strat, dis);
}

void	print_bench_stats(t_bench *b)
{
	int	total;

	if (!b->is_active)
		return ;
	total = b->ops.sa + b->ops.sb + b->ops.ss + b->ops.pa + b->ops.pb
		+ b->ops.ra + b->ops.rb + b->ops.rr + b->ops.rra + b->ops.rrb
		+ b->ops.rrr;
	print_header(b->disorder, b->strat);
	put_metric("[bench] total_ops: ", total);
	ft_putstr_fd("\n", 2);
	put_metric("[bench] sa: ", b->ops.sa);
	put_metric(" sb: ", b->ops.sb);
	put_metric(" ss: ", b->ops.ss);
	put_metric(" pa: ", b->ops.pa);
	put_metric(" pb: ", b->ops.pb);
	ft_putstr_fd("\n", 2);
	put_metric("[bench] ra: ", b->ops.ra);
	put_metric(" rb: ", b->ops.rb);
	put_metric(" rr: ", b->ops.rr);
	put_metric(" rra: ", b->ops.rra);
	put_metric(" rrb: ", b->ops.rrb);
	put_metric(" rrr: ", b->ops.rrr);
	ft_putstr_fd("\n", 2);
}
