/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 10:08:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 10:48:26 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

int ft_printf (const char *format, ...)
{
	va_list ap;
	int i;
	t_printf *wip;

	wip->formats = ft_strdup(format);
	wip->strdone = ft_strdup("");
	i = -1;
	va_start(ap, format);
	if (wip->formats)
		while (wip->formats[++i] != '\0')
		{
			if (format[i] == '%')
				i = ft_parse(wip, i);
		}
	write(1, wip->strdone, wip->size_strdone);
	free(wip->strdone);
	return(wip->size_strdone);
}
