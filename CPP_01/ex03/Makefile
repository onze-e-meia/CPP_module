# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 16:29:50 by tforster          #+#    #+#              #
#    Updated: 2024/10/17 17:49:24 by tforster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#    Name                                                                      #
# **************************************************************************** #

NAME	:=	violence

# **************************************************************************** #
#    Sources                                                                   #
# **************************************************************************** #

SRC_DIR	:=	src
SRC		:=	\
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp \
	main.cpp
SRC		:= $(addprefix $(SRC_DIR)/, $(SRC))

# **************************************************************************** #
#    Dependencies                                                              #
# **************************************************************************** #

INC_DIR		:= \
	include

# **************************************************************************** #
#    Build                                                                     #
# **************************************************************************** #

OBJ_DIR :=	obj
OBJ		:=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP		:=	$(OBJ:.o=.d)

CC		:=	c++
FLAGS	:=	-Wall -Wextra -Werror -std=c++98
INCLUDE	:=	$(addprefix -I, $(INC_DIR)) -MMD -MP

# **************************************************************************** #
#    Misc                                                                      #
# **************************************************************************** #

RM			:= rm -rf

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

# 1: action, 2: target, 3: color
define message
	$(info [$(TITLE)] $(3)$(1)$(RESET) $(2))
endef

ifdef WITH_DEBUG
	TITLE	+= $(MAGENTA)debug$(RESET)
	FLAGS	+= -g3
else
	FLAGS	+= -O3
endif

# **************************************************************************** #
#    Targets                                                                   #
# **************************************************************************** #

all: $(NAME) ## Build the program

debug: ## Build the program with debug symbols
	$(MAKE) WITH_DEBUG=TRUE all

loose: ## Build the program ignoring warnings
	$(MAKE) FLAGS="$(filter-out -Werror,$(FLAGS))" all

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) -o $(NAME)
	$(call message,BINARY,$(NAME),$(BLUE))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@
	$(call message,OBJECT,$@,$(GREEN))

clean: ## Remove all generated object files
	$(RM) $(OBJ_DIR)
	$(call message,DELETED,$(OBJ_DIR),$(RED))

fclean: clean ## Remove all generated files
	$(RM) $(NAME)
	$(call message,DELETED,$(NAME),$(RED))

re: ## Rebuild the program
	$(MAKE) fclean
	$(MAKE) all

run: $(NAME) ## Run the program
	$(call message,RUNNING,./$(NAME),$(CYAN))
	./$(NAME)

help: ## Show this message
	echo "$(BOLD)Usage: make [<name>=<value>...]$(RESET) $(BOLD)$(CYAN)[target...]$(RESET)"
	echo
	echo "$(BOLD)Targets:$(RESET)"
	grep -E '^[a-zA-Z_.%-]+:.*?## .*$$' Makefile \
	| awk 'BEGIN {FS = ":.*?## "}; {printf "%2s$(CYAN)%-20s$(RESET) %s\n", "", $$1, $$2}'

.PHONY: all debug loose clean fclean re run help
.SILENT:
.DELETE_ON_ERROR:

-include $(DEP)
