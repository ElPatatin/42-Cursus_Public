# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barce>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 16:24:27 by cpeset-c          #+#    #+#              #
#    Updated: 2022/12/07 16:57:34 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBRARY	= library/
LIB_DIR	= libft/
PNT_DIR	= liboutput/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIB_NAME	= libft.a
OUT_NAME	= liboutput.a

LIBFT	= $(LIB_DIR)$(LIB_NAME)
PRINT	= $(PNT_DIR)$(OUT_NAME)

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all:
	@$(MAKE) makelibft
	@$(MAKE) makeprint

libft:
	@$(MAKE) makelibft

print:
	@$(MAKE)makeprint

#-=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=-=--=- #

makelibft:
	@$(MAKE) -C $(LIB_DIR)
	@$(CP) $(LIBFT) ./

makeprint:
	@$(MAKE) -C $(PNT_DIR)
	@$(CP) $(PRINT) ./

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(MAKE) clean -C $(PNT_DIR)

fclean:
	@$(RM) $(LIB_NAME) $(OUT_NAME) ./*.out
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(MAKE) fclean -C $(PNT_DIR)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY:	all libft printf gnl clean fclean re
