# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 16:19:46 by myagiz            #+#    #+#              #
#    Updated: 2023/01/04 17:43:32 by myagiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Name:
NAME	=
CLIENT	=	client
SERVER	=	server
B_CLIENT	=	client_bonus
B_SERVER	=	server_bonus

#ft_printf Variables:
LIBFTPRINTF	=	ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	ft_printf

#minitalk variables
SRC_C	=	ft_client.c
SRC_S	=	ft_server.c
OBJ_C	=	ft_client.o
OBJ_S	=	ft_server.o

#minitalk bonus

B_SRC_C	=	ft_client_bonus.c
B_SRC_S	=	ft_server_bonus.c
B_OBJ_C	=	ft_client_bonus.o
B_OBJ_S	=	ft_server_bonus.o

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

#Colors:
GREEN		=	\e[38;5;118m
BLUE		=	\e[38;5;39m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(BLUE)INFO$(RESET)]

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER) $(B_CLIENT) $(B_SERVER)

$(SERVER): $(OBJ_S)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server ready.\n"
$(CLIENT): $(OBJ_C)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)
	@printf "$(_SUCCESS) client ready.\n"

$(B_SERVER): $(B_OBJ_S)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(B_OBJ_S)
	@printf "$(_SUCCESS) server_bonus ready.\n"

$(B_CLIENT): $(B_OBJ_C)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(B_OBJ_C)
	@printf "$(_SUCCESS) client_bonus ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S) $(B_OBJ_C) $(B_OBJ_S)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER) $(B_CLIENT) $(B_SERVER)
	@printf "$(_INFO) bonus removed.\n"

re: fclean all

.PHONY: all clean fclean re
