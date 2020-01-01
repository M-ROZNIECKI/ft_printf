# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/14 12:45:05 by mrozniec     #+#   ##    ##    #+#        #
#    Updated: 2020/01/01 20:19:27 by fenrir      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = libftprintf.a

ifeq ($(shell uname), Linux)
TARGET = linux/libft.a
else
TARGET = mac/libft.a
endif

SRC =	ft_printf.c\
		ft_parse.c\
		ft_convert.c\
		ft_wchar_utf_8.c\
		ft_localetest.c\
		convertion/ft_cmin_conv.c\
		convertion/ft_dmin_conv.c\
		convertion/ft_nmin_conv.c\
		convertion/ft_pmin_conv.c\
		convertion/ft_smin_conv.c\
		convertion/ft_umin_conv.c\
		convertion/ft_xmin_conv.c\
		convertion/ft_xmaj_conv.c\
		convertion/ft_omin_conv.c\
		convertion/ft_perc_conv.c\
		convertion/ft_gmin_conv.c\
		convertion/ft_fmin_conv.c\
		convertion/ft_emin_conv.c\
		convertion/ft_efgmin_select.c\
		convertion/ft_float_utils.c\
		flags/ft_apost.c\
		flags/ft_hash.c\
		flags/ft_hflags.c\
		flags/ft_hhflags.c\
		flags/ft_lflags.c\
		flags/ft_llflags.c\
		flags/ft_plus.c\
		flags/ft_precision.c\
		flags/ft_size_champ.c\
		flags/ft_space.c\
		flags/ft_zero.c

HEADER =	libft.h\
			libftprintf.h\
			convertion/libconv.h\
			flags/libflag.h

OBJ =	$(SRC:.c=.o)

OBJ_FT =	temp_file/ft_atoi.o\
			temp_file/ft_atof.o\
			temp_file/ft_bzero.o\
			temp_file/ft_calloc.o\
			temp_file/ft_isalnum.o\
			temp_file/ft_isalpha.o\
			temp_file/ft_isascii.o\
			temp_file/ft_isdigit.o\
			temp_file/ft_isprint.o\
			temp_file/ft_itoa.o\
			temp_file/ft_llitoa.o\
			temp_file/ft_itoa_base.o\
			temp_file/ft_hitoa_base.o\
			temp_file/ft_hhitoa_base.o\
			temp_file/ft_litoa_base.o\
			temp_file/ft_llitoa_base.o\
			temp_file/ft_memccpy.o\
			temp_file/ft_memchr.o\
			temp_file/ft_memcmp.o\
			temp_file/ft_memcpy.o\
			temp_file/ft_memmove.o\
			temp_file/ft_memset.o\
			temp_file/ft_putchar_fd.o\
			temp_file/ft_putendl_fd.o\
			temp_file/ft_putnbr_fd.o\
			temp_file/ft_putstr_fd.o\
			temp_file/ft_split.o\
			temp_file/ft_strchr.o\
			temp_file/ft_strdup.o\
			temp_file/ft_strjoin.o\
			temp_file/ft_strjoinmod.o\
			temp_file/ft_strjoinmodnbits.o\
			temp_file/ft_strlcat.o\
			temp_file/ft_strlcpy.o\
			temp_file/ft_strlen.o\
			temp_file/ft_strmapi.o\
			temp_file/ft_strncmp.o\
			temp_file/ft_strnstr.o\
			temp_file/ft_strrchr.o\
			temp_file/ft_strtrim.o\
			temp_file/ft_substr.o\
			temp_file/ft_tolower.o\
			temp_file/ft_toupper.o

OBJ_FTMP =	ft_atoi.o\
			ft_atof.o\
			ft_bzero.o\
			ft_calloc.o\
			ft_isalnum.o\
			ft_isalpha.o\
			ft_isascii.o\
			ft_isdigit.o\
			ft_isprint.o\
			ft_itoa.o\
			ft_llitoa.o\
			ft_itoa_base.o\
			ft_hitoa_base.o\
			ft_hhitoa_base.o\
			ft_litoa_base.o\
			ft_llitoa_base.o\
			ft_memccpy.o\
			ft_memchr.o\
			ft_memcmp.o\
			ft_memcpy.o\
			ft_memmove.o\
			ft_memset.o\
			ft_putchar_fd.o\
			ft_putendl_fd.o\
			ft_putnbr_fd.o\
			ft_putstr_fd.o\
			ft_split.o\
			ft_strchr.o\
			ft_strdup.o\
			ft_strjoin.o\
			ft_strjoinmod.o\
			ft_strjoinmodnbits.o\
			ft_strlcat.o\
			ft_strlcpy.o\
			ft_strlen.o\
			ft_strmapi.o\
			ft_strncmp.o\
			ft_strnstr.o\
			ft_strrchr.o\
			ft_strtrim.o\
			ft_substr.o\
			ft_tolower.o\
			ft_toupper.o

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar x $(TARGET)
	@mv $(OBJ_FTMP) temp_file/
	@ar rc $(NAME) $(OBJ) $(OBJ_FT)

%.o: %.c
	@cc -o $@ -c $< -Wall -Wextra -Werror

.PHONY: clean fclean re all

clean:
	@/bin/rm -f $(OBJ) $(OBJ_FT)

fclean: clean
	@/bin/rm -rf $(NAME) __.SYMDEF\ SORTED

re: fclean all
