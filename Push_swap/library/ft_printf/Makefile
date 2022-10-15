# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 12:16:37 by cpeset-c          #+#    #+#              #
#    Updated: 2022/10/15 10:13:36 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= libprintf.a
MKFL		= Makefile

# -=-=-=-=-	CLRS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR	:= \033[0;39m
GRAY		:= \033[0;90m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
WHITE		:= \033[0;97m

# -=-=-=-=-	CMND -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

CFLAGS	= -Wall -Werror -Wextra -W -O3 -Ofast
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

PRT_SRC		= ft_printf.c

PRT_UTL		= ft_char_utils.c \
		ft_nbrs_utils.c \
		ft_vptr.c

SRCS	+=	$(addprefix $(SRC_DIR), $(PRT_SRC))
SRCS	+=	$(addprefix $(UTL_DIR), $(PRT_UTL))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(MKFL)
	@$(MD) $(dir $@)
	@printf "$(WHITE)\r\tCompiling: $(YELLOW)$<$(DEF_COLOR)                           \r"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(CP) $(LIBS) ./$(NAME)
	@$(AR) $(NAME) $(OBJS)
	@printf "$(CYAN)\n\tThe library $(GREEN)'printf'$(CYAN) has been compiled!\n$(DEF_COLOR)"

$(NAME)::
	@printf "\t$(WHITE)Nothing more to be done for library \033[1;31m$(NAME)\n"

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)	Printf object files cleaned.$(DEF_COLOR)"

fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:	fclean	all
	@$(MAKE) fclean
	@$(MAKE) all
	@echo ""
	@echo "$(GREEN)	Cleaned and rebuilt everything for printf lib.$(DEF_COLOR)"

-include $(DEPS)

.PHONY:	all clean fclean re
