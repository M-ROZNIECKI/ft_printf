/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/27 09:15:42 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 12:12:32 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static int	len_champ(t_printf *wip, int i)
{
	if (wip->formats[i] == '0')
		wip->flags = wip->flags | ZERO;
	if (wip->formats[i] == '*' ||
		(wip->formats[i] == '0' && wip->formats[i + 1] == '*'))
	{
		wip->size_champ = va_arg(wip->ap, size_t);
		if (wip->size_champ < 0)
		{
			wip->size_champ = -wip->size_champ;
			wip->flags = wip->flags | MINUS;
		}
		if (wip->formats[i] == '0')
			i++;
		i++;
	}
	else
	{
		wip->size_champ = wip->formats[i++] - '0';
		while (wip->formats[i] >= '0' && wip->formats[i] <= '9')
		{
			wip->size_champ = wip->size_champ * 10 + (wip->formats[i++] - '0');
		}
	}
	return (i);
}

static void	fill_sym(t_printf *wip, int n)
{
	if (n < 14)
		wip->conv = 1 << n;
	else if (n < 18)
		wip->flags = wip->flags | (1 << (n - 14));
	else if (n == 18)
	{
		if ((wip->flags & H_MIN) != 0)
			wip->flags = (wip->flags & ~H_MIN) | HH_MIN;
		else
			wip->flags = wip->flags | H_MIN;
	}
	else if (n == 19)
	{
		if ((wip->flags & L_MIN) != 0)
			wip->flags = (wip->flags & ~L_MIN) | LL_MIN;
		else
			wip->flags = wip->flags | L_MIN;
	}
	else
		wip->flags = wip->flags | (1 << (n - 12));
}

static int	check(t_printf *wip, int i)
{
	int		n;

	n = -1;
	if (wip->formats[i] == '*')
		wip->precision = va_arg(wip->ap, int);
	while (SYMBOL[++n])
	{
		if (wip->formats[i] == SYMBOL[n])
		{
			if (((SYMBOL[n] == '0') && (wip->formats[i - 1] != '.')) ||
				((SYMBOL[n] != '0')))
				fill_sym(wip, n);
			return (0);
		}
	}
	if ((wip->formats[i - 1] == '.') && (wip->formats[i] != '*'))
		wip->precision = ft_atoi(&wip->formats[i]);
	return (1);
}

static void	ft_init(t_printf *wip)
{
	wip->conv = INIT_C;
	wip->flags = INIT_F;
	wip->strloc = ft_strdup(setlocale(LC_CTYPE, NULL));
	wip->precision = 0;
	wip->size_champ = 0;
	wip->neg = '0';
	wip->error = 0;
}

int			ft_parse(t_printf *wip, int i)
{
	char *temp_form;

	temp_form = wip->formats;
	ft_init(wip);
	temp_form[i] = '\0';
	while (wip->formats[++i] && wip->conv == 0)
	{
		if (((wip->formats[i] >= '0' && wip->formats[i] <= '9') ||
			wip->formats[i] == '*') && ((wip->flags & POINT) == 0))
			i = len_champ(wip, i);
		check(wip, i);
	}
	ft_localetest(wip);
	if (wip->error == 1)
		return (-1);
	wip->strdone = ft_strjoinmod(wip->strdone, wip->formats, 1);
	wip->formats = ft_strdup(&temp_form[i]);
	free(temp_form);
	temp_form = ch_conv1(wip);
	if ((wip->flags & SPACE) && (wip->neg == '0'))
		wip->strdone = ft_strjoinmod(wip->strdone, " ", 1);
	wip->strdone = ft_strjoinmod(wip->strdone, temp_form, 3);
	free(wip->strloc);
	return (-1);
}