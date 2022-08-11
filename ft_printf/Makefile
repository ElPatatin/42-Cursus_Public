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

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR := \033[0;39m
GRAY := \033[0;90m
RED := \033[0;91m
GREEN := \033[0;92m
YELLOW := \033[0;93m
BLUE := \033[0;94m
MAGENTA := \033[0;95m
CYAN := \033[0;96m
WHITE := \033[0;97m

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
		ft_vptr.c \
		ft_width.c

SRCS	+=	$(addprefix $(SRC_DIR), $(PRT_SRC))
SRCS	+=	$(addprefix $(UTL_DIR), $(PRT_UTL))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEP		= $(addsuffix .d, $(basename $(OBJS)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@$(MD) $(dir $@)
	@echo ""
	@echo "$(RED)	Compiling: $(YELLOW)$< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all: make_lib $(NAME)

make_lib:
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIBS)
	@$(CP) $(LIBS) ./$(NAME)
	@echo "$(GRAY)	Copied the libft compiled.$(DEF_COLOR)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(CYAN)	Printf lib compiled!$(DEF_COLOR)"

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)	Printf object files cleaned.$(DEF_COLOR)"

fclean:	clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME)
	@echo ""
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:	fclean	all
	@echo ""
	@echo "$(GREEN)	Cleaned and rebuilt everything for libft.$(DEF_COLOR)"

-include $(DEP)

.PHONY:	all clean fclean re make_lib
