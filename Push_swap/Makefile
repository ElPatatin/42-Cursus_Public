# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 19:49:08 by cpeset-c          #+#    #+#              #
#    Updated: 2022/10/07 09:12:28 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= push_swap
BNUS		= checker
MKFL		= Makefile

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR	:= \033[0;39m
BLACK		:= \033[0;30m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
GRAY		:= \033[0;90m
WHITE		:= \033[0;97m

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

CFLAGS	= -Wall -Werror -Wextra -W -O3 -Ofast
XFLAGS  = -fsanitize=address -g3
RM		= rm -f
MD		= mkdir -p
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

INC_DIR	= inc/
SRC_DIR	= src/
UTL_DIR	= utils/
TUL_DIR	= tools/
OBJ_DIR	= obj/
BNS_DIR	= bonus/
LIB_DIR	= library/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBS	= $(LIB_DIR)lib.a
HDRS	= $(INC_DIR)push_swap.h $(INC_DIR)moves.h
INCLUDE	= -I $(INC_DIR)

SRC_PSH	= push_swap.c \
		check_input.c \
		init_stacks.c \
		small_sorting.c \
		big_sorting.c

UTL_PSH = push_swap_utils.c \
		sort_utils.c \
		errors.c

TUL_PSH	= push.c \
		swap.c \
		rotate.c \
		rrotate.c

SRCS	+= $(addprefix $(SRC_DIR), $(SRC_PSH))
SRCS	+= $(addprefix $(UTL_DIR), $(UTL_PSH))
SRCS	+= $(addprefix $(TUL_DIR), $(TUL_PSH))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))

# -=-=-=-=-	BNUS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

HDRS_BNUS	= $(BNS_DIR)$(INC_DIR)push_swap.h $(BNS_DIR)$(INC_DIR)moves.h
INCLUDE_B	= -I $(BNS_DIR)$(INC_DIR)

SRC_BNS	= checker_bonus.c \
		check_input_bonus.c \
		init_stacks_bonus.c

UTL_BNS = push_swap_utils_bonus.c \
		errors_bonus.c

TUL_BNS	= push_bonus.c \
		swap_bonus.c \
		rotate_bonus.c \
		rrotate_bonus.c

SRCS_BNUS	+= $(addprefix $(BNS_DIR), $(addprefix $(SRC_DIR), $(SRC_BNS)))
SRCS_BNUS	+= $(addprefix $(BNS_DIR), $(addprefix $(UTL_DIR), $(UTL_BNS)))
SRCS_BNUS	+= $(addprefix $(BNS_DIR), $(addprefix $(TUL_DIR), $(TUL_BNS)))

OBJS_BNUS	= $(addprefix $(OBJ_DIR), $(SRCS_BNUS:.c=.o))
DEPS_BNUS	= $(addsuffix .d, $(basename $(OBJS_BNUS)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: %.c $(MKFL)
	@$(MD) $(dir $@)
	@printf "\r$(GREEN)\tCompiling: $(YELLOW)$< $(DEF_COLOR)                   \r"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) $(INCLUDE_B) -c $< -o $@

all: makelib $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@printf "\n\t$(WHITE)Program \033[1;31mPush Swap $(WHITE)has been compiled!\n"

bonus: makelib $(BNUS)

$(BNUS): $(OBJS_BNUS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS_BNUS) $(LIBS) -o $(BNUS)
	@printf "\r\n\t$(WHITE)Program \033[1;31mChecker $(WHITE)has been compiled!\n"

makelib:
	@make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR) $(BNS_DIR)$(OBJ_DIR)
	@echo ""
	@echo "	$(WHITE)All objects and dependencies removed for \033[1;31mPush Swap.$(DEF_COLOR)"

fclean:	clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(NAME) $(BNUS)
	@echo ""
	@echo "	$(WHITE)All objects, dependencies and executables removed for \033[1;31mPush Swap.$(DEF_COLOR)"

re:	fclean	all

-include $(DEPS)
-include $(DEPS_BNUS)

.PHONY:	all clean fclean re makelibs bonus
