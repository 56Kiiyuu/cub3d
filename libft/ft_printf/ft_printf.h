/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:47:03 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 16:06:36 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printhex(unsigned int n, const char type);
int		ft_printptr(unsigned long long ptr);
int		ft_printuint(unsigned int n);
int		ft_printper(void);

void	ft_putstr(char *str);
int		ft_hexalen(unsigned int n);
void	ft_puthexa(unsigned int n, const char type);
int		ft_ptrlen(unsigned long long n);
void	ft_putptr(unsigned long long n);
int		ft_uintlen(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);

#endif
