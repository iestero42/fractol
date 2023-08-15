# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 10:56:39 by yunlovex          #+#    #+#              #
#    Updated: 2023/08/15 11:09:17 by iestero-         ###   ########.fr        #
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

SMILEY				=	\xF0\x9F\x98\x81
CHECK				=	\xE2\x9C\x85

LIBS_DIR			=	libs
LIBFRACTOL			=	$(LIBS_DIR)/libfractol.a
LIBFRACTOL_BONUS	=	$(LIBS_DIR)/libfractolbonus.a

LIBFT_DIR			=	./libft
LIBFT				=	$(LIBFT_DIR)/libft.a

MINILIBX_DIR		=	./minilibx
MINILIBX			=	$(MINILIBX_DIR)/libmlx.a

OBJ_DIR				=	build
OBJBNS_DIR			=	buildbonus
SRC_DIR				=	src
SRCBNS_DIR			= 	srcbonus

INC_DIR				=	inc
INCBONUS_DIR		=	incbonus

MAIN_DIR			=	main
UTILS_DIR			=	utils

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

UTILS_FILES	=	


SRCS_FILES	= 	$(addprefix $(MAIN_DIR)/, $(MAIN_FILES)) \

SRCS 		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS 		=	$(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))
DIRS		=	$(OBJ_DIR)  $(addprefix $(OBJ_DIR)/, $(MAIN_DIR) $(UTILS_DIR))

OBJ_MAIN	=	$(addprefix $(OBJ_DIR)/, $(addprefix $(MAIN_DIR)/, $(MAIN_FILES:.c=.o)))

# Source Bonus

MAIN_BONUS_FILES	=	pipex_bonus.c			\

UTILS_BONUS_FILES	=	childs_bonus.c			\
						errors_bonus.c			\
						exec_comand_bonus.c		\
						free_bonus.c			\
						math_utils_bonus.c		\
						here_doc_bonus.c		\

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
	@echo "\n$(GREEN)   Deleting files...$(NC)"	
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MINILIBX_DIR)
	@$(RM) -r $(LIBS_DIR)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(OBJBNS_DIR)

fclean:				clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re:					fclean all

print_mandatory:
	@echo "\n******************************************************"
	@echo "*                                                    *"
	@echo "*                                                    *"
	@echo "*              $(YELLOW)Compiling Mandatory Part$(NC)              *"
	@echo "*                                                    *"
	@echo "*                                                    *"
	@echo "******************************************************"

# Mandatory

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c | $(DIRS) $(LIBS_DIR)
	@make print_mandatory
	@echo "\n$(GREEN)   ---Compiling: $(LIGHT_GRAY)$<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJ_MAIN) $(LIBFRACTOL) $(LIBFT) $(MINILIBX)
	@$(CC) $? $(LDFLAGS) -o $@
	@echo "\n$(GREEN)   The program is ready.$(SMILEY) $(CHECK)$(NC)"	

$(LIBFT):
	@echo "$(GREEN)   ---Compiling: $(LIGHT_GRAY)libft$(NC)"	
	@make -C $(LIBFT_DIR)

$(MINILIBX):
	@echo "$(GREEN)   ---Compiling: $(LIGHT_GRAY)minilibx$(NC)"
	@make -C $(MINILIBX_DIR)

$(LIBFRACTOL): 		$(OBJS)
	@$(AR) $(ARFLAGS) $@ $?

$(DIRS):
	@$(MKDIR) $@

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