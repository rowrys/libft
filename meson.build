project (
	'libft',
	'c',
	version : '0.1.0',
	default_options : [
		'warning_level=3',
		'optimization=3',
		'c_std=c11',
		'werror=true',
		'debug=true',
	]
)

add_project_arguments(
	'-pedantic-errors',
	language : 'c'
)

sources = files (
	'srcs/stdlib/ft_atoi.c',
	'srcs/stdlib/ft_atoi_base.c',
	'srcs/stdlib/ft_calloc.c',
	'srcs/stdlib/ft_split.c',
	'srcs/stdlib/ft_itoa.c',
	'srcs/stdlib/ft_itoa_buffer.c',
	'srcs/stdlib/ft_atol.c',
	'srcs/stdlib/ft_safe_close.c',
	'srcs/stdlib/ft_vecb.c',
	'srcs/stdlib/gnl/get_next_line.c',
	'srcs/stdlib/gnl/get_number_line_file.c',
	'srcs/ctype/ft_isalnum.c',
	'srcs/ctype/ft_isalpha.c',
	'srcs/ctype/ft_isascii.c',
	'srcs/ctype/ft_isdigit.c',
	'srcs/ctype/ft_isprint.c',
	'srcs/ctype/ft_tolower.c',
	'srcs/ctype/ft_toupper.c',
	'srcs/mem/ft_memchr.c',
	'srcs/mem/ft_memcmp.c',
	'srcs/mem/ft_memcpy.c',
	'srcs/mem/ft_memset.c',
	'srcs/mem/ft_memmove.c',
	'srcs/mem/ft_bzero.c',
	'srcs/str/ft_strchr.c',
	'srcs/str/ft_check_chrs.c',
	'srcs/str/ft_strdup.c',
	'srcs/str/ft_tab_strdup.c',
	'srcs/str/ft_strlcat.c',
	'srcs/str/ft_strlcpy.c',
	'srcs/str/ft_strcpy.c',
	'srcs/str/ft_strlen.c',
	'srcs/str/ft_strncmp.c',
	'srcs/str/ft_strcmp.c',
	'srcs/str/ft_strend.c',
	'srcs/str/ft_strnstr.c',
	'srcs/str/ft_strrchr.c',
	'srcs/str/ft_substr.c',
	'srcs/str/ft_strjoin.c',
	'srcs/str/ft_strtrim.c',
	'srcs/str/ft_strmapi.c',
	'srcs/str/ft_striteri.c',
	'srcs/stdio/ft_putchar_fd.c',
	'srcs/stdio/ft_putstr_fd.c',
	'srcs/stdio/ft_putendl_fd.c',
	'srcs/stdio/ft_putnbr_fd.c',
	'srcs/stdio/printf/ft_printf.c',
	'srcs/stdio/printf/ft_printf_putstr.c',
	'srcs/stdio/printf/ft_printf_putnbr.c',
	'srcs/lst/ft_lstnew.c',
	'srcs/lst/ft_lstadd_front.c',
	'srcs/lst/ft_lstsize.c',
	'srcs/lst/ft_lstlast.c',
	'srcs/lst/ft_lstadd_back.c',
	'srcs/lst/ft_lstdelone.c',
	'srcs/lst/ft_lstclear.c',
	'srcs/lst/ft_lstiter.c',
	'srcs/lst/ft_lstmap.c'
)

includes = include_directories('includes')
subdir('includes')

libft = both_libraries (
	'ft',
	sources,
	install : true,
	include_directories : includes,
)

libft_dep = declare_dependency(include_directories : includes, link_with: libft)
meson.override_dependency('libft', libft_dep)