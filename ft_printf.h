/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:43:10 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/19 12:43:12 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char);
void	ft_putstr(char *);
size_t	ft_strlen(const char *c);
int		ft_printf(const char *, ...);
int     ft_itoa_unsigned(unsigned int);
int		ft_itoa(int);
char	isconvchar(char);
int		convert_to_basesix(unsigned long long int, short);

#endif
