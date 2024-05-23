# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/18 14:32:36 by rkaras        #+#    #+#                  #
#    Updated: 2024/05/20 15:24:13 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
LIBFT_PATH = Libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -I$(LIBFT_PATH)/include
LDFLAGS = -L$(LIBFT_PATH) -lft

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT_LIB)
	$(CC) $(LDFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJ) $(LIBFT_LIB)
	$(CC) $(LDFLAGS) $^ -o $@

$(CLIENT_OBJ): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OBJ): $(SERVER_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	make -C $(LIBFT_PATH) fclean

re: fclean all