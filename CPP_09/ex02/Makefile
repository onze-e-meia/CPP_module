# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 16:29:50 by tforster          #+#    #+#              #
#    Updated: 2025/03/19 17:27:40 by tforster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#    Name                                                                      #
# **************************************************************************** #

NAME	:=	PmergeMe

# **************************************************************************** #
#    Sources                                                                   #
# **************************************************************************** #

SRC_DIR	:=	src

SRC	:=	\
	main.cpp \
	parser.cpp \
	CtrlVar.cpp \
	PmergeMe.cpp \
	print_array.cpp

SRC	:= $(addprefix $(SRC_DIR)/, $(SRC))

# **************************************************************************** #
#    Dependencies                                                              #
# **************************************************************************** #

INC_DIR	:=	src/include

LIB_DIR	:=	src/lib

# **************************************************************************** #
#    Build                                                                     #
# **************************************************************************** #

OBJ_DIR :=	obj
OBJ		:=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP		:=	$(OBJ:.o=.d)

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98
INCLUDE	:=	$(addprefix -I , $(INC_DIR)) -MMD -MP
LIB		:=	$(addprefix -I , $(LIB_DIR)) -MMD -MP

# DEBUG	=	-O3
DEBUG	=
MSG		=
SANITIZE=

# **************************************************************************** #
#    Misc                                                                      #
# **************************************************************************** #

RM		:= rm -rf

RED			:= $(shell tput setaf 1)
GREEN		:= $(shell tput setaf 2)
YELLOW		:= $(shell tput setaf 3)
BLUE		:= $(shell tput setaf 4)
MAGENTA		:= $(shell tput setaf 5)
CYAN		:= $(shell tput setaf 6)
WHITE		:= $(shell tput setaf 7)
ERROR		:= $(shell tput setab 1)$(WHITE)
SUCCESS		:= $(shell tput setab 2)$(WHITE)
WARNING		:= $(shell tput setab 3)$(WHITE)
INFO		:= $(shell tput setab 4)$(WHITE)
BOLD		:= $(shell tput bold)
RESET		:= $(shell tput sgr0)
CLEAR		:= $(shell tput cuu1; tput el)
TITLE		:= $(YELLOW)$(basename $(NAME))$(RESET)
TITLE_LOOSE	:= $(TITLE) $(MAGENTA)disable Werror$(RESET)
TITLE_MSG	:= $(TITLE) $(MAGENTA)with message$(RESET)
TITLE_DEBUG	:= $(TITLE) $(MAGENTA)debug$(RESET)
TITLE_ASAN	:= $(TITLE) $(MAGENTA)address sanitizer$(RESET)

# 1: action, 2: target, 3: color
define message
	$(info [$(TITLE)] $(3)$(1)$(RESET) $(2))
endef

# **************************************************************************** #
#    Targets                                                                   #
# **************************************************************************** #

all: $(NAME) ## Build the program

$(NAME): $(OBJ)
#	$(CC) $(SANITIZE) $(DEBUG) $(MSG) $(FLAGS) $(OBJ) -o $(NAME)
	$(CC) $(MSG) $(FLAGS) $(OBJ) -o $(NAME)
	$(call message,BINARY,$(NAME),$(BLUE))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(SANITIZE) $(DEBUG) $(MSG) $(FLAGS) $(INCLUDE) $(LIB) -c $< -o $@
	$(call message,OBJECT,$@,$(GREEN))

loose:	## Build the program ignoring warnings
	$(MAKE) TITLE="$(TITLE_LOOSE)" FLAGS="$(filter-out -Werror,$(FLAGS))"

msg:	## Build the program with Constructor messages enabled
	$(MAKE) TITLE="$(TITLE_MSG)" MSG="-DMSG"

debug:	## Build the program with Debug symbols
	$(MAKE) TITLE="$(TITLE_DEBUG)" DEBUG=-"g3" FLAGS="$(filter-out -Werror,$(FLAGS))"

asan:	## Build the program with Debug and Address Sanitizer
	$(MAKE) TITLE="$(TITLE_ASAN)" SANITIZE="-fsanitize=address" DEBUG="-g3"

clean:	## Remove all generated object files
	$(RM) $(OBJ_DIR)
	$(call message,DELETED,$(OBJ_DIR),$(RED))

fclean:	## Remove all generated files
	$(MAKE) clean
	$(RM) $(NAME)
	$(call message,DELETED,$(NAME),$(RED))

re:		## Rebuild the program
	$(MAKE) fclean
	$(MAKE)

help:	## Show this message
	echo "$(BOLD)Usage: make [<name>=<value>...]$(RESET) $(BOLD)$(CYAN)[target...]$(RESET)"
	echo
	echo "$(BOLD)Targets:$(RESET)"
	grep -E '^[a-zA-Z_.%-]+:.*?## .*$$' Makefile \
	| awk 'BEGIN {FS = ":.*?## "}; {printf "%2s$(CYAN)%-20s$(RESET) %s\n", "", $$1, $$2}'

.PHONY: all debug loose clean fclean re run msg help
.SILENT:
.DELETE_ON_ERROR:

-include $(DEP)
