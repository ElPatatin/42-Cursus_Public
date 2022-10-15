# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 16:24:27 by cpeset-c          #+#    #+#              #
#    Updated: 2022/10/15 10:44:02 by cpeset-c         ###   ########.fr        #
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

all:
	@$(MAKE) libft
	@$(MAKE) printf
	@$(MAKE) gnl

libft:
	@$(MAKE) -C $(LIB_DIR)
	@$(CP) $(LIBFT) ./$(NAME)


printf:
	@$(MAKE) -C $(PNT_DIR)
	@$(CP) $(PRINTF) ./$(NAME)

gnl:
	@$(MAKE) -C $(GNL_DIR)
	@$(CP) $(FUNGNL) ./$(NAME)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(MAKE) clean -C $(PNT_DIR)
	@$(MAKE) clean -C $(GNL_DIR)

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME) ./*.out
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(MAKE) fclean -C $(PNT_DIR)
	@$(MAKE) fclean -C $(GNL_DIR)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY:	all libft printf gnl clean fclean re
