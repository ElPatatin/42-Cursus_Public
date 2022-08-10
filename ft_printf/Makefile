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

CFLAGS		= -Wall -Werror -Wextra -g
AR		= ar rcs
RM		= rm -f
MD		= mkdir -p
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC_DIR	= src/
UTL_DIR	= utils/
OBJ_DIR	= obj/
INC_DIR	= inc/
LIB_DIR	= libft/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBS		= $(LIB_DIR)libft.a
#LIB_FT		= -I $(LIB_DIR)$(INC_DIR)lib_ft.h
INCLUDE		= -I $(INC_DIR)ft_printf.h

PRT_SRC		= ft_printf.c \
		ft_checker.c

PRT_UTL		= ft_char_utils.c \
		ft_nbrs_utils.c \
		ft_vptr.c

SRCS	+=	$(addprefix $(SRC_DIR), $(PRT_SRC))
SRCS	+=	$(addprefix $(UTL_DIR), $(PRT_UTL))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP		= $(addsuffix .d, $(basename $(OBJS)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(MD) $(dir $@)
	$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all: make_lib $(NAME)

make_lib:
	make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBS)
	$(CP) $(LIBS) ./$(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	make clean -C $(LIB_DIR)
	$(RM) -r $(OBJ_DIR)
	$(RM) $(OBJF)

fclean:	clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re:	fclean	all

-include $(DEP)

.PHONY:	all clean fclean re make_lib
