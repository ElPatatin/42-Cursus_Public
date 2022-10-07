# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 16:24:27 by cpeset-c          #+#    #+#              #
#    Updated: 2022/10/07 06:49:56 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME	= lib.a

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBRARY	= library/
LIB_DIR	= libft/
PNT_DIR	= ft_printf/
GNL_DIR	= ft_gnl/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBFT	= $(LIB_DIR)libft.a
PRINTF	= $(PNT_DIR)libprintf.a
FUNGNL	= $(GNL_DIR)libgnl.a

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: makelibft makeprintf makegnl

libft: makelibft

printf: makelibft makeprintf

gnl: makelibft makegnl

#-=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=- #

makelibft:
	@make -C $(LIB_DIR)
	@$(CP) $(LIBFT) ./$(NAME)

makeprintf:
	@make -C $(PNT_DIR)
	@$(CP) $(PRINTF) ./$(NAME)

makegnl:
	@make -C $(GNL_DIR)
	@$(CP) $(FUNGNL) ./$(NAME)

clean:
	@make clean -C $(LIB_DIR)
	@make clean -C $(PNT_DIR)
	@make clean -C $(GNL_DIR)

fclean: clean
	@$(RM) $(NAME) ./*.out
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(PNT_DIR)
	@make fclean -C $(GNL_DIR)

re: fclean all

.PHONY:	all libft printf gnl clean fclean re
