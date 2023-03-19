/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:45:26 by minkim3           #+#    #+#             */
/*   Updated: 2023/03/15 13:42:54 by minkim3          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 8

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct t_options_type
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	int		width;
	int		width_have;
	int		precision;
	int		precision_have;
	int		type;
	char	*value;
	char	*space;
	char	*prefix;
	char	*print;
	int		val_minus;
	int		val_zero;
	int		val_null;
	int		strlen;
	int		malloc_error;
}	t_options;

int			ft_percent_or_other(char c);
int			ft_flag_checker(char c);
void		ft_flag_check(char c, t_options *string_info, size_t *index);
void		ft_width_check(const char *format, size_t *index, \
			t_options *string_info);
void		ft_precision_check(const char *format, size_t *index, \
			t_options *string_info);
int			ft_type_checker(char c);
int			ft_option_error(t_options *string_info);
int			ft_error_quit(va_list *ap, t_options *string_info);
void		ft_decimal_to_string(t_options *string_info, int decimal);
void		ft_decimal_to_hexadecimal(t_options *string_info, \
			unsigned int decimal);
char		*ft_pointer_to_lowercase_hexadecimal(unsigned long long decimal);
void		ft_apply_int(t_options *string_info, int value);
void		ft_apply_unsigned_int(t_options *string_info, unsigned int value);
void		ft_apply_percent(t_options *string_info, int value);
void		ft_apply_string(t_options *string_info, char *value);
void		ft_apply_pointer(t_options *string_info, unsigned long long value);
int			ft_apply_option(va_list *ap, t_options *string_info);
void		ft_apply_flag(t_options *string_info);
char		*ft_strjoin_three(char	*s1, char *s2, char *s3);
char		*ft_get_cpy_with_this(t_options *string_info, char star, int len);
char		*new_string_with_this(char star, size_t strlen);
void		ft_putchar(char c, int *strlen);
int			ft_malloc_error_int(t_options *string_info);
void		*ft_malloc_error_null(t_options *string_info);
void		ft_malloc_error_void(t_options *string_info);
int			ft_printf(const char *format, ...);
void		ft_apply_flag_minus(t_options *string_info);
void		ft_print_t_options(t_options *string_info);
void		ft_free_options(t_options *string_info);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
char		*ft_new_string(size_t strlen);
char		*ft_itoa_extension(unsigned long long n);
char		*get_next_line(int fd);
ssize_t		find_char(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*append_buffer(char const *s1, char const *s2, size_t len);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
long long	ft_atoi_extension(const char *str);
int			error_return(char *message, int return_value);
void		free_two_dementional_array(char **array);

#endif
