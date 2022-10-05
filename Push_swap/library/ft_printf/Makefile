# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 12:16:37 by cpeset-c          #+#    #+#              #
#    Updated: 2022/10/03 00:09:13 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= libprintf.a

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

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBS		= ../lib.a
INCLUDE		= -I $(INC_DIR)

PRT_SRC		= ft_printf.c \
		ft_char_utils.c \
		ft_nbrs_utils.c \
		ft_vptr.c

SRCS	+=	$(addprefix $(SRC_DIR), $(PRT_SRC))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MD) $(dir $@)
	@echo "$(RED)	Compiling: $(YELLOW)$< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CP) $(LIBS) ./$(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(CYAN)	Printf lib compiled!$(DEF_COLOR)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)	Printf object files cleaned.$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:	fclean	all
	@echo ""
	@echo "$(GREEN)	Cleaned and rebuilt everything for printf lib.$(DEF_COLOR)"

-include $(DEPS)

.PHONY:	all clean fclean re
