/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:12:04 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/03 16:12:06 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:12:04 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/14 16:44:42 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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
int     ft_itoa(int);
char	isconvchar(char);
int     convert_to_basesix(long long int, short);

#endif
