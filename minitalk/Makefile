# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 18:26:09 by cpeset-c          #+#    #+#              #
#    Updated: 2022/09/11 12:23:53 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= .minitalk
BNUS		= .minitalk_bonus
CLI_NAME	= client
SRV_NAME	= server

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

CFLAGS	= -Wall -Werror -Wextra -g
XFLAGS  = -fsanitize=address -g3
AR		= ar -rcs
RM		= rm -f
MD		= mkdir -p
CP		= cp -f

# -=-=-=-=-	PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC_DIR	= src/
UTL_DIR	= utils/
OBJ_DIR	= obj/
INC_DIR	= inc/
LIB_DIR	= library/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBS	= $(LIB_DIR)lib.a
INCLUDE	= -I $(INC_DIR)
HDRS	= $(INC_DIR)minitalk.h

CLI_SRC	= client.c
SRV_SRC	= server.c
UTL_SRC	= minitalk_utils.c

SRC_CLI	+= $(addprefix $(SRC_DIR), $(CLI_SRC))
SRC_CLI	+= $(addprefix $(UTL_DIR), $(UTL_SRC))

SRC_SRV	+= $(addprefix $(SRC_DIR), $(SRV_SRC))
SRC_SRV	+= $(addprefix $(UTL_DIR), $(UTL_SRC))

OBJ_CLI	= $(addprefix $(OBJ_DIR), $(SRC_CLI:.c=.o))
DEP_CLi	= $(addsuffix .d, $(basename $(OBJ_CLI)))

OBJ_SRV	= $(addprefix $(OBJ_DIR), $(SRC_SRV:.c=.o))
DEP_SRV	= $(addsuffix .d, $(basename $(OBJ_SRV)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: %.c Makefile
	@$(MD) $(dir $@)
	@echo "$(GREEN)	Compiling: $(YELLOW)$< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all: makelib $(NAME)

$(NAME): $(OBJ_CLI) $(OBJ_SRV) $(HDRS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJ_CLI) $(LIBS) -o $(CLI_NAME)
	@echo "$(CYAN)	Client side compiled!$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJ_SRV) $(LIBS) -o $(SRV_NAME)
	@echo "$(CYAN)	Server side compiled!$(DEF_COLOR)"
	@touch $@

makelib:
	@make -C $(LIB_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)	Printf objects files cleaned.$(DEF_COLOR)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(CLI_NAME) $(SRV_NAME) $(NAME) $(BNUS)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:	fclean	all
	@echo ""
	@echo "$(GREEN)	Cleaned and rebuilt everything for printf lib.$(DEF_COLOR)"

-include $(DEP_CLi) $(DEP_SRV)

.PHONY:	all makelib clean fclean re
