# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 10:56:39 by yunlovex          #+#    #+#              #
#    Updated: 2023/09/08 12:53:22 by iestero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variable

NAME				=	fract-ol
BONUS				=	fract-ol_bonus

GREEN 				= 	\033[0;32m
LIGHT_GRAY 			= 	\033[90m
BLUE 				= 	\033[0;34m
NC 					= 	\033[0m
YELLOW				=	\033[93m

MANDATORY_PART 		=	"\n ******************************************************\n				\
						*                                                    *\n					\
						*                                                    *\n					\
						*                   $(YELLOW)MANDATORY PART$(NC)                   *\n		\
						*                                                    *\n					\
						*                                                    *\n					\
						******************************************************\n\n"
BONUS_PART 			=	"\n ******************************************************\n				\
						*                                                    *\n					\
						*                                                    *\n					\
						*                     $(YELLOW)BONUS PART$(NC)                     *\n		\
						*                                                    *\n					\
						*                                                    *\n					\
						******************************************************\n\n"					\

SMILEY				=	\xF0\x9F\x98\x81
CHECK				=	\xE2\x9C\x85

LIBS_DIR			=	libs
LIBFRACTOL			=	$(LIBS_DIR)/libfractol.a
LIBFRACTOL_BONUS	=	$(LIBS_DIR)/libfractolbonus.a

LIBFT_DIR			=	./libft
LIBFT				=	$(LIBFT_DIR)/libft.a

MINILIBX_DIR		=	minilibx
MINILIBX			=	$(MINILIBX_DIR)/libmlx.a

OBJ_DIR				=	build
OBJBNS_DIR			=	buildbonus
SRC_DIR				=	src
SRCBNS_DIR			= 	srcbonus

INC_DIR				=	inc
INCBONUS_DIR		=	incbonus

MAIN_DIR			=	main
UTILS_DIR			=	utils
PARSE_DIR			=	parse

LDLIBS				=	$(LIBFRACTOL) $(LIBFT)
LDLIBS_BONUS		=	$(LIBFRACTOL_BONUS) $(LIBFT)

CC					=	gcc

CFLAGS				=	-g -Wall -Werror -Wextra $(INCLUDES)
CFLAGS_BONUS		=	-g -Wall -Werror -Wextra $(INCLUDES_BONUS)
LDFLAGS				=	$(LDLIBS) -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
LDFLAGS_BONUS		=	$(LDLIBS_BONUS) -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDES			=	-I$(INC_DIR) -I$(addsuffix $(INC_DIR), $(LIBFT_DIR)/) -I$(MINILIBX_DIR)
INCLUDES_BONUS		=	-I$(INCBONUS_DIR) -I$(addsuffix $(INC_DIR), $(LIBFT_DIR)/) -I$(MINILIBX_DIR)

SANITIZE			=	-fsanitize=address

MKDIR				=	mkdir -p
RM					=	rm -f
AR					= 	ar

ARFLAGS 			= 	rsc

# Source

MAIN_FILES	=	fract-ol.c

PARSE_FILES	=	fractal_init.c			\
				fractal_render.c		\
				colors.c				\
				choose_ft.c				\

UTILS_FILES	=	math_utils.c		\
				pixel_put.c			\
				events.c			\
				ft_atod.c			\
				math_utils2.c		\


SRCS_FILES	= 	$(addprefix $(MAIN_DIR)/, $(MAIN_FILES)) 	\
				$(addprefix $(UTILS_DIR)/, $(UTILS_FILES)) 	\
				$(addprefix $(PARSE_DIR)/, $(PARSE_FILES)) 	\

SRCS 		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS 		=	$(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))
DIRS		=	$(OBJ_DIR)  $(addprefix $(OBJ_DIR)/, $(MAIN_DIR) $(UTILS_DIR) $(PARSE_DIR))

OBJ_MAIN	=	$(addprefix $(OBJ_DIR)/, $(addprefix $(MAIN_DIR)/, $(MAIN_FILES:.c=.o)))

# Source Bonus

MAIN_BONUS_FILES	=	pipex_bonus.c			\

UTILS_BONUS_FILES	=	childs_bonus.c			\
						errors_bonus.c			\
						exec_comand_bonus.c		\
						free_bonus.c			\
						math_utils_bonus.c		\
						here_doc_bonus.c		\
						colors.c				\

SRCSBONUS_FILES		=	$(addprefix $(MAIN_DIR)/, $(MAIN_BONUS_FILES)) \
						$(addprefix $(UTILS_DIR)/, $(UTILS_BONUS_FILES)) \

SRCSBONUS 			=	$(addprefix $(SRCBNS_DIR)/, $(SRCSBONUS_FILES))
OBJSBONUS 			=	$(addprefix $(OBJBNS_DIR)/, $(SRCSBONUS_FILES:.c=.o))
DIRSBONUS			=	$(OBJBNS_DIR) $(addprefix $(OBJBNS_DIR)/, $(UTILS_DIR) $(MAIN_DIR))

OBJBONUS_MAIN		=	$(addprefix $(OBJBNS_DIR)/, $(addprefix $(MAIN_DIR)/, $(MAIN_BONUS_FILES:.c=.o)))

# Rules

all:				$(NAME)

bonus:				$(BONUS)

clean:
	@make -s fclean -C $(LIBFT_DIR)
	@make -s clean -C $(MINILIBX_DIR)
	@$(RM) -r $(LIBS_DIR)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJBNS_DIR)
	@echo "---- $(YELLOW)Object files deleted. $(CHECK)$(NC) ----"

fclean:				clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@echo "---- $(YELLOW)Binary files deleted. $(CHECK)$(NC) ----"

re:					fclean all

# Mandatory

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c | $(DIRS) $(LIBS_DIR)
	@printf "\r\r\t---> $(BLUE)Compiling:\t$(LIGHT_GRAY)$<$(NC)\033[K"
	@sleep 0.5
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ_MAIN) $(LIBFRACTOL) $(LIBFT) $(MINILIBX)
	@$(CC) $(OBJ_MAIN) $(LDFLAGS) -o $@
	@sleep 1
	@echo "\n$(GREEN)The program is ready.$(SMILEY) $(CHECK)$(NC)"	

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(MINILIBX):
	@echo "\n   ---> $(BLUE)Creating:\t$(LIGHT_GRAY)minilibx$(NC)"
	@make -s  -C $(MINILIBX_DIR)
	@echo "   $(CHECK) $(GREEN)Library created.$(NC)"

$(LIBFRACTOL): 		$(OBJS)
	@$(AR) $(ARFLAGS) $@ $?
	@echo "\n   $(CHECK) $(GREEN)Library created.$(NC)"

$(DIRS):
	@echo $(MANDATORY_PART)
	@echo "\n   ---> $(BLUE)Creating:\t$(LIGHT_GRAY)libPipex$(NC)"
	@$(MKDIR) $(DIRS)

$(LIBS_DIR):
	@$(MKDIR) $@


# Bonus

$(OBJBNS_DIR)/%.o:		$(SRCBNS_DIR)/%.c | $(DIRSBONUS) $(LIBS_DIR)
	@$(CC) $(CFLAGS_BONUS) -c $< -o $@				

$(LIBPIPEX_BONUS): 		$(OBJSBONUS)
	$(AR) $(ARFLAGS) $@ $?

$(DIRSBONUS):
	$(MKDIR) $@

$(BONUS):				$(OBJBONUS_MAIN) $(LIBPIPEX_BONUS) $(LIBFT) 
	$(CC) $? $(LDFLAGS_BONUS) -o $(NAME)
	@touch $@	

.SILENT:			clean fclean
.PHONY:				all clean fclean re bonus