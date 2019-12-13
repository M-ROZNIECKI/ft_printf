/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libconv.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 02:30:42 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 05:24:36 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBCONV_H
# define LIBCONV_H
# include "../libftprintf.h"
# include "../flags/libflag.h"

char	*ft_xmin_conv(t_printf *wip);
char	*ft_xmaj_conv(t_printf *wip);
char	*ft_umin_conv(t_printf *wip);
char	*ft_dmin_conv(t_printf *wip);
char	*ft_perc_conv(t_printf *wip);
char	*ft_cmin_conv(t_printf *wip);
char	*ft_smin_conv(t_printf *wip);
char	*ft_pmin_conv(t_printf *wip);
char	*ft_nmin_conv(t_printf *wip);
#endif
