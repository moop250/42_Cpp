# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlibine <hlibine@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:51:54 by hlibine           #+#    #+#              #
#    Updated: 2024/09/04 16:03:53 by hlibine          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
DEVFLAGS	= -g3
RM			= rm -rf

OBJDIR		= .obj

# Colors
GREEN		= \033[0;32m
ORANGE		= \033[38;5;208m
RESET		= \033[0m\n

# Files

CPP 		= main
CLASS		= PhoneBook
FILES		= $(CPP:= $(CLASS))

SRCS		= $(FILES:=.cpp)
OBJS		= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= $(CLASS:=.hpp)
# Rules
all: $(NAME)

$(NAME): $(SRCS) $(HEADER) $(OBJS)
	@printf "$(FILES)\n$(SRCS)\n$(HEADER)\n"
	@printf "$(ORANGE)Compiling $(NAME)$(RESET)"
	@ $(CC) $(OBJS) -o $(NAME)
	@printf "$(GREEN)$(NAME) compiled$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@printf "$(ORANGE)Compiling object files$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@printf "$(GREEN)Object files compiled$(RESET)"

debug: $(EXFT_LIB)
	@printf "$(ORANGE)Compiling debug $(NAME)$(RESET)"
	@$(CC) $(DEVFLAGS) $(SRCS) $(SUPP) -o $(NAME)
	@printf "$(GREEN) Debug $(NAME) compiled$(RESET)"

clean:
	@printf "$(ORANGE)Cleaning up...$(RESET)"
	@$(RM) $(OBJDIR) $(OBJS)
	@printf "$(GREEN)Clean up successful$(RESET)"

s_clean:
	@$(RM) $(NAME) $(OBJDIR) $(OBJS)

fclean: s_clean
	@printf "$(ORANGE)Full clean up...$(RESET)"
	@$(RM) $(NAME)
	@printf "$(GREEN)Full clean up successful$(RESET)"

re: fclean all

help:
	@echo "\033[0;36mmake\033[0m : complies the project."
	@echo "\033[0;36mmake all\033[0m : complies the project."
	@echo "\033[0;36mmake re\033[0m : recompiles the project."
	@echo "\033[0;36mmake debug\033[0m : runs the program in debug mode."
	@echo "\033[0;36mmake clean\033[0m : removes the executable."
	@echo "\033[0;36mmake fclean\033[0m : removes the executable."

.PHONY: all clean fclean re debug help
