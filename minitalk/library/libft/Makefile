# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 19:35:19 by cpeset-c          #+#    #+#              #
#    Updated: 2022/09/18 17:40:47 by cpeset-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-	NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

NAME		= libft.a

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
OBJ_DIR	= obj/
INC_DIR	= inc/

FIS_DIR	= $(SRC_DIR)ft_is/
MTH_DIR = $(SRC_DIR)ft_math/
MEM_DIR	= $(SRC_DIR)ft_mem/
PUT_DIR	= $(SRC_DIR)ft_put/
SRT_DIR	= $(SRC_DIR)ft_sort/
STR_DIR	= $(SRC_DIR)ft_str/

# -=-=-=-=-	FILE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

INCLUDE		= -I $(INC_DIR)

FIS_SRC	= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_islower.c ft_isupper.c ft_isprint.c ft_isspace.c

MTH_SRC	= ft_absval.c ft_atoi.c ft_atoi_base.c ft_factorial.c \
		ft_find_next_prime.c ft_itoa.c ft_itoa_base.c ft_lcm.c \
		ft_nbrlen.c ft_nbrlen_base.c ft_power.c ft_prime.c \
		ft_sqrt.c

MEM_SRC	= ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c \
		ft_memfree.c ft_memmove.c ft_memset.c ft_range.c \
		ft_rrange.c ft_strdup.c ft_ultrange.c

PUT_SRC	= ft_putchar.c ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c \
		ft_putnbr_base_fd.c ft_putstr.c ft_putstr_fd.c

SRT_SRC	= ft_adv_sort_str_tab.c ft_any.c ft_count_if.c ft_foreach.c \
		ft_is_sort.c ft_map.c ft_rev_int_tab.c ft_sort_int_tab.c \
		ft_sort_str_tab.c ft_split.c ft_striteri.c ft_strmapi.c \
		ft_swap.c 

STR_SRC	= ft_str_wcount.c ft_strcapitalize.c ft_strchr.c ft_strrchr.c \
		ft_strcmp.c ft_strcpy.c ft_strcspn.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c  ft_strncmp.c \
		ft_strnstr.c ft_strtrim.c ft_strupcase.c ft_strlowcase.c \
		ft_substr.c ft_tolower.c ft_toupper.c

SRCS	+= $(addprefix $(FIS_DIR), $(FIS_SRC))
SRCS	+= $(addprefix $(MTH_DIR), $(MTH_SRC))
SRCS	+= $(addprefix $(MEM_DIR), $(MEM_SRC))
SRCS	+= $(addprefix $(PUT_DIR), $(PUT_SRC))
SRCS	+= $(addprefix $(SRT_DIR), $(SRT_SRC))
SRCS	+= $(addprefix $(STR_DIR), $(STR_SRC))

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	= $(addsuffix .d, $(basename $(OBJS)))

# -=-=-=-=-	RULE -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MD) $(dir $@)
	@echo "$(WHITE)	Compiling: $(YELLOW)$< $(DEF_COLOR)"
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(CYAN)	Function library 'libft' compiled!$(DEF_COLOR)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)	Libft object files cleaned.$(DEF_COLOR)"

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(WHITE)	All objects, dependencies and executables removed.$(DEF_COLOR)"

re:	fclean	all
	@echo ""
	@echo "$(GREEN)	Cleaned and rebuilt everything for libft.$(DEF_COLOR)"

-include $(DEPS)

.PHONY:	all clean fclean re
