# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 12:38:29 by cpeset-c          #+#    #+#              #
#    Updated: 2022/07/05 22:31:11 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
HDRS		= libft.h
TORM		= .bonus

CC		= cc
CFLAGS		= -Wall -Werror -Wextra
NORM		= norminette -R CheckForbbiddenSourceHeader
AR		= ar -rcs
RM		= rm -f

SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	  			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)

BNUS		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c $(SRCS)

OBJSB		= $(BNUS:.c=.o)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(AR) $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(OBJSB) $(HDRS)
	$(AR) $(NAME) $(OBJSB)
	touch .bonus

clean:
	$(RM) $(OBJS) $(OBJSB)
	@echo "\n\t...Borrando todos los Objetos...\n " 

fclean: clean
	$(RM) $(NAME) $(TORM)
	@echo "\t...Borrando la libreria...\n"

re: fclean all

.PHONY: all clean fclean re
