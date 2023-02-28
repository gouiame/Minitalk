# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 12:18:09 by cgouiame          #+#    #+#              #
#    Updated: 2023/02/27 17:12:08 by cgouiame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CLIENT_SRC = client.c utils.c
SERVER_SRC = server.c utils.c

SRC_BONUS_CLIENT = client_bonus.c utils_bonus.c
SRC_BONUS_SERVER = server_bonus.c utils_bonus.c

OBJ_CLIENT = $(CLIENT_SRC:.c=.o)
OBJ_SERVER = $(SERVER_SRC:.c=.o)

OBJ_BONUS_CLIENT = $(SRC_BONUS_CLIENT:.c=.o)
OBJ_BONUS_SERVER = $(SRC_BONUS_SERVER:.c=.o)

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_CLIENT): $(OBJ_CLIENT) 
		 		cc -Wall -Werror -Wextra $(OBJ_CLIENT) -o $(NAME_CLIENT)
$(NAME_SERVER) : $(OBJ_SERVER)
		 		 cc -Wall -Werror -Wextra $(OBJ_SERVER) -o $(NAME_SERVER)

bonus : $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS) : $(OBJ_BONUS_SERVER)
						cc -Wall -Wextra -Werror $(OBJ_BONUS_SERVER) -o $(NAME_SERVER_BONUS)
						
$(NAME_CLIENT_BONUS) : $(OBJ_BONUS_CLIENT)
						cc -Wall -Wextra -Werror $(OBJ_BONUS_CLIENT) -o $(NAME_CLIENT_BONUS)
						
%.o : %.c minitalk.h minitalk_bonus.h
		cc -Wall -Wextra -Werror -c $< 											

clean :
		 rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_BONUS_CLIENT) $(OBJ_BONUS_SERVER)

fclean : clean
		 rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re : fclean all bonus
