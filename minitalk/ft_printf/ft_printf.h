/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:35:58 by myagiz            #+#    #+#             */
/*   Updated: 2022/12/28 17:36:01 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_base(unsigned int nbr, char Xx);
int	ft_putaddr(void *addr);
int	ft_atoi(const char *str);

#endif
