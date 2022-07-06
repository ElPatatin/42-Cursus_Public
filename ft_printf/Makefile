# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 12:16:37 by cpeset-c          #+#    #+#              #
#    Updated: 2022/07/06 18:40:05 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #


NAME		= libftprintf.a

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

CC		= cc -c
CFLAGS		= -Wall -Werror -Wextra -MMD $(INCLUDE)
AR		= ar -rcs
RM		= rm -f
MKDIR		= mkdir -p
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC_DIR	= src/
OBJ_DIR	= obj/
INC_DIR	= inc/
LIB_DIR	= libft/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBS		= $(LIB_DIR)libft.a
LIBS_HDRS	= -I $(LIB_DIR)libft.h
INCLUDE		= -I $(INC_DIR) $(LIBS_HDRS)

SRCS		= ft_printf.c \
		ft_char_utils.c \
		ft_nbrs_utils.c \
		ft_vptr.c \

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP		= $(addsuffix .d, $(basename $(OBJS)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -o $@ $<

all: make_libs $(NAME)

make_libs:
	make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBS)
	$(CP) $(LIBS) ./$(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	make clean -C $(LIB_DIR)
	$(RM) -r $(OBJ_DIR)

fclean:	clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re:	fclean	all

// This rule automaticatly look for all the dependencies in the lib
// and redo all project if needed.
-include $(DEP)

.PHONY:	all clean fclean re make_libs
