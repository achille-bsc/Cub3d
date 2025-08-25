# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abosc <abosc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 01:08:11 by lvan-bre          #+#    #+#              #
#    Updated: 2025/08/25 23:11:19 by abosc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC					:=	gcc
CFLAGS				:=	-Wextra -Wall -Werror -g
MLXFLAGS			:=	 -L/usr/bin -lX11 -lXext -lXrandr -lXi -lXinerama -lXcursor -lm -lz
VALFLAGS			:=	--leak-check=full --show-leak-kinds=all --track-fds=yes --trace-children=yes --track-origins=yes --suppressions=/home/lvan-bre/Tronc_commun/Foxy_munch/additional_files/readline.supp

# COMMANDS

RM					:=	rm -f
RMDIR				:=	rm -rf

# DIRS

BIN					:=	bin
BUILD				:=	build
SRC_DIR				:=	src
INC_DIR				:=	headers
BUILD_SRC			:=	$(BUILD)/$(SRC_DIR)
DEP					:=	Depedencies
ARCH				:=	$(BIN)/archives

# TARGET

TARGET				:=	cub3d
NAME				:=	$(BIN)/$(TARGET)
TARGET_H			:=	cub3d.h

# LIBFT

LIBFT_TARGET		:=	libft.a
LIBFT_H				:=	libft.h
LIBFT_DIR			:=	Libft_Updated
LIBFT_PATH			:=	$(DEP)/$(LIBFT_DIR)
LIBFT_H_PATH		:=	$(LIBFT_PATH)/$(LIBFT_H)
FT_PRINTF_H			:=	ft_printf.h
FT_PRINTF_H_PATH	:=	$(LIBFT_PATH)/$(FT_PRINTF_H)
GNL_H				:=	get_next_line.h
GNL_H_PATH			:=	$(LIBFT_PATH)/$(GNL_H)
LIBFT_GIT			:=	https://github.com/Sellith/Libft_Updated.git

# MLX

MLX_TARGET			:=	libmlx.a
MLX_H_FILE			:=	mlx.h
MLX_DIR				:=	minilibx-linux
MLX_PATH			:=	$(DEP)/$(MLX_DIR)
MLX_H_PATH			:=	$(MLX_PATH)/$(MLX_H_FILE)
MLX_TARGET_PATH		:=	$(MLX_PATH)/$(MLX_TARGET)
MLX_GIT				:=	https://github.com/42Paris/minilibx-linux.git

# INCLUDES & ARCHIVES

ARCHIVES			:=	$(ARCH)/$(LIBFT_TARGET) $(ARCH)/$(MLX_TARGET)
INCLUDES			:=	$(INC_DIR)/

# SRC DIRS

RC					:=	raycasting
EV					:=	events

# COLORS_DEFINITIONS

CLR_RESET	=	\033[0m
CLR_RED		=	\033[1;91m
CLR_GRN		=	\033[1;92m
CLR_YLW		=	\033[1;93m
CLR_BLUE	=	\033[1;94m
CLR_PPL		=	\033[1;95m
CLR_LPPL	=	\033[1;35m
CLR_CYAN	=	\033[1;96m
CLR_WTH		=	\033[1;97m

ERS_STR		=	\033[2K\r

#	SRC FILES

SRC		=	main.c $(EV)/events.c

#	OBJS CONVERSION

OBJS	=	$(patsubst %.c, $(BUILD_SRC)/%.o, $(SRC))

#	RULES

all:	$(NAME)

clean:
	@$(RMDIR) $(BUILD)
	@$(MAKE) clean -C $(LIBFT_PATH) --no-print-directory

fclean: clean
	@$(RMDIR) $(BIN)
	@$(MAKE) fclean -C $(LIBFT_PATH) --no-print-directory

re:	fclean all

cleandep:
	@$(MAKE) clean -C $(LIBFT_PATH) --no-print-directory

fcleandep:
	@$(MAKE) fclean -C $(LIBFT_PATH) --no-print-directory

mkdep:
	@cp $(LIBFT_H_PATH) $(INC_DIR)
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory

redep: fcleandep mkdep

cleansrc:
	@$(RMDIR) $(BUILD_SRC)

fcleansrc: cleansrc
	@$(RM) $(NAME)

resrc: fcleansrc all

normy:
	@norminette $(SRC_DIR) $(LIBFT_PATH) | grep -Ev 'Notice|OK!$$'	\
	&& echo '$(CLR_RED)Norminette : KO !$(CLR_RESET)'					\
	|| echo '$(CLR_CYAN)Norminette : OK !$(CLR_RESET)'

libft:
	@printf "$(CLR_BLUE)\tInfo:\t\t$(CLR_CYAN)Cloning $(CLR_LPPL)\"%s\"$(CLR_CYAN) into $(CLR_LPPL)\"%s\"...$(CLR_RESET)" $(LIBFT_DIR) $(DEP)
	@git clone -q $(LIBFT_GIT) $(LIBFT_PATH)
	@printf "$(ERS_STR)$(CLR_BLUE)\tInfo:\t\t$(CLR_YLW)\"%s\" $(CLR_GRN) Cloned into $(CLR_YLW) \"%s\" !$(CLR_RESET)\n" $(LIBFT_DIR) $(DEP)
	@$(RMDIR) $(LIBFT_PATH)/.git
	@cp $(LIBFT_H_PATH) $(INC_DIR)
	@cp $(FT_PRINTF_H_PATH) $(INC_DIR)
	@cp $(GNL_H_PATH) $(INC_DIR)

rmlibft:
	@$(RMDIR) $(LIBFT_PATH)
	@printf "$(CLR_BLUE)\tInfo:\t\t$(CLR_RED)Removed \"%s\" !$(CLR_RESET)\n" $(LIBFT_DIR)

mlx:
	@printf "$(CLR_BLUE)\tInfo:\t\t$(CLR_CYAN)Cloning $(CLR_LPPL)\"%s\"$(CLR_CYAN) into $(CLR_LPPL)\"%s\"...$(CLR_RESET)" $(MLX_DIR) $(DEP)
	@git clone -q $(MLX_GIT) $(MLX_PATH)
	@printf "$(ERS_STR)$(CLR_BLUE)\tInfo:\t\t$(CLR_YLW)\"%s\" $(CLR_GRN) Cloned into $(CLR_YLW) \"%s\" !$(CLR_RESET)\n" $(MLX_DIR) $(DEP)
	@$(MAKE) -C $(MLX_PATH) --no-print-directory > /dev/null 2>&1
	@mkdir -p $(ARCH)
	@cp $(MLX_TARGET_PATH) $(ARCH)
	@cp $(MLX_H_PATH) $(INC_DIR)

rmmlx:
	@$(RMDIR) $(MLX_PATH)
	@printf "$(CLR_BLUE)\tInfo:\t\t$(CLR_RED)Removed \"%s\" !$(CLR_RESET)\n" $(MLX_DIR)

udlib: fcleandep rmlibft libft redep

.PHONY: all clean fclean re cleandep fcleandep mkdep redep cleansrc fcleansrc resrc val normy libft rmlibft udlib

# COMPILATION

$(NAME):	$(OBJS)
	@printf "$(ERS_STR)$(CLR_BLUE)\tSource files:\t$(CLR_GRN)Compilation succeded !$(CLR_RESET)\n"
	@mkdir -p $(@D)
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	@$(MAKE) -C $(MLX_PATH) --no-print-directory > /dev/null 2>&1
	@mkdir -p $(ARCH)
	@cp $(MLX_TARGET_PATH) $(ARCH)
	@cp $(MLX_H_PATH) $(INC_DIR)
	@$(CC) $(OBJS) -I$(INC_DIR) $(ARCHIVES) -o $@ $(MLXFLAGS)
	@printf "$(ERS_STR)$(CLR_BLUE)\tDone Building:\t$(CLR_LPPL)\"%s\"$(CLR_GRN) in $(CLR_LPPL)\"%s/\"$(CLR_GRN)!$(CLR_RESET)\n" $(TARGET) $(BIN)

$(BUILD_SRC)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) $(MLXFLAGS)
	@printf "$(ERS_STR)$(CLR_CYAN)\tCompiling: $(CLR_PPL)\"%s\"$(CLR_CYAN)..." $<