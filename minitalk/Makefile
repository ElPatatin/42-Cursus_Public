# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 18:26:09 by cpeset-c          #+#    #+#              #
#    Updated: 2022/10/17 16:20:45 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= minitalk
CLI_NAME	= client
CL2_NAME	= client2
CL3_NAME	= client3
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
CL2_SRC	= client2.c
CL3_SRC	= client3.c
SRV_SRC	= server.c
UTL_SRC	= minitalk_utils.c

SRC_CLI	+= $(addprefix $(SRC_DIR), $(CLI_SRC))
SRC_CLI	+= $(addprefix $(UTL_DIR), $(UTL_SRC))

SRC_CL2	+= $(addprefix $(SRC_DIR), $(CL2_SRC))
SRC_CL2	+= $(addprefix $(UTL_DIR), $(UTL_SRC))

SRC_CL3	+= $(addprefix $(SRC_DIR), $(CL3_SRC))
SRC_CL3	+= $(addprefix $(UTL_DIR), $(UTL_SRC))

SRC_SRV	+= $(addprefix $(SRC_DIR), $(SRV_SRC))
SRC_SRV	+= $(addprefix $(UTL_DIR), $(UTL_SRC))

OBJ_CLI	= $(addprefix $(OBJ_DIR), $(SRC_CLI:.c=.o))
DEP_CLI	= $(addsuffix .d, $(basename $(OBJ_CLI)))

OBJ_CL2	= $(addprefix $(OBJ_DIR), $(SRC_CL2:.c=.o))
DEP_CL2	= $(addsuffix .d, $(basename $(OBJ_CL2)))

OBJ_CL3	= $(addprefix $(OBJ_DIR), $(SRC_CL3:.c=.o))
DEP_CL3	= $(addsuffix .d, $(basename $(OBJ_CL3)))

OBJ_SRV	= $(addprefix $(OBJ_DIR), $(SRC_SRV:.c=.o))
DEP_SRV	= $(addsuffix .d, $(basename $(OBJ_SRV)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: %.c Makefile
	@$(MD) $(dir $@)
	@echo "$(GREEN)	Compiling: $(YELLOW)$< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)

$(NAME):
	@$(MAKE) $(CLI_NAME)
	@$(MAKE) $(CL2_NAME) 
	@$(MAKE) $(CL3_NAME)
	@$(MAKE) $(SRV_NAME)
	
$(CLI_NAME):: $(OBJ_CLI)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJ_CLI) $(LIBS) -o $(CLI_NAME)
	@echo "$(CYAN)	Client side compiled!$(DEF_COLOR)"

$(CLI_NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mClient 1.\n"

-include $(DEP_CLI)

$(CL2_NAME):: $(OBJ_CL2)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJ_CL2) $(LIBS) -o $(CL2_NAME)
	@echo "$(CYAN)	Client side for files compiled!$(DEF_COLOR)"

$(CL2_NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mClient 2.\n"

-include $(DEP_CL2)

$(CL3_NAME):: $(OBJ_CL3)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJ_CL3) $(LIBS) -o $(CL3_NAME)
	@echo "$(CYAN)	Client side for files compiled!$(DEF_COLOR)"

$(CL3_NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mClient 3.\n"

-include $(DEP_CL3)

$(SRV_NAME):: $(OBJ_SRV)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJ_SRV) $(LIBS) -o $(SRV_NAME)
	@echo "$(CYAN)	Server side compiled!$(DEF_COLOR)"

$(SRV_NAME)::
	@printf "\t$(WHITE)Nothing more to be done for program \033[1;31mServer.\n"

-include $(DEP_SRV)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)	Printf objects files cleaned.$(DEF_COLOR)"

fclean:
	@$(MAKE) clean
	@$(MAKE) fclean -C $(LIB_DIR)
	@$(RM) $(CLI_NAME) $(CL2_NAME) $(CL3_NAME) $(SRV_NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
	@echo ""
	@echo "$(GREEN)	Cleaned and rebuilt everything for printf lib.$(DEF_COLOR)"

.PHONY:	all makelib clean fclean re
