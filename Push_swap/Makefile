# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 19:49:08 by cpeset-c          #+#    #+#              #
#    Updated: 2022/10/15 10:26:45 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= push_swap
CHKR		= checker
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
CHK_DIR	= extra/
LIB_DIR	= library/

DEP_LIB	= $(LIB_DIR)*/$(OBJ_DIR)$(SRC_DIR)*/*.o

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

# -=-=-=-=-	CHKR -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

HDRS_CHKR	= $(CHK_DIR)$(INC_DIR)push_swap_extra.h $(CHK_DIR)$(INC_DIR)moves_extra.h
INCLUDE_B	= -I $(CHK_DIR)$(INC_DIR)

SRC_CHK	= checker_extra.c \
		check_input_extra.c \
		init_stacks_extra.c

UTL_CHK = push_swap_utils_extra.c \
		errors_extra.c

TUL_CHK	= push_extra.c \
		swap_extra.c \
		rotate_extra.c \
		rrotate_extra.c

SRCS_CHKR	+= $(addprefix $(CHK_DIR), $(addprefix $(SRC_DIR), $(SRC_CHK)))
SRCS_CHKR	+= $(addprefix $(CHK_DIR), $(addprefix $(UTL_DIR), $(UTL_CHK)))
SRCS_CHKR	+= $(addprefix $(CHK_DIR), $(addprefix $(TUL_DIR), $(TUL_CHK)))

OBJS_CHKR	= $(addprefix $(OBJ_DIR), $(SRCS_CHKR:.c=.o))
DEPS_CHKR	= $(addsuffix .d, $(basename $(OBJS_CHKR)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: %.c $(MKFL) $(DEP_LIB)
	@$(MD) $(dir $@)
	@printf "\r$(GREEN)\tCompiling: $(YELLOW)$< $(DEF_COLOR)                   \r"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) $(INCLUDE_B) -c $< -o $@

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@printf "\n\t$(WHITE)Program \033[1;31mPush Swap $(WHITE)has been compiled!\n"

$(NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mPush Swap\n"

extra:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(CHKR)

$(CHKR):: $(OBJS_CHKR)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS_CHKR) $(LIBS) -o $(CHKR)
	@printf "\r\n\t$(WHITE)Program \033[1;31mChecker $(WHITE)has been compiled!\n"

$(CHKR)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mChecker\n"

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR)
	@echo ""
	@echo "	$(WHITE)All objects and dependencies removed for \033[1;31mPush Swap.$(DEF_COLOR)"

fclean:
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(MAKE) clean
	@$(RM) $(NAME) $(CHKR)
	@echo ""
	@echo "	$(WHITE)All objects, dependencies and executables removed for \033[1;31mPush Swap.$(DEF_COLOR)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

-include $(DEPS)
-include $(DEPS_CHKR)

.PHONY:	all clean fclean re extra