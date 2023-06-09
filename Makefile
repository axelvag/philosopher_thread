.PHONY:								all $(NAME) clean fclean re mkbuild lib

GREEN								= \033[1;32m
PURPLE								= \033[1;35m
END									= \033[0m

NAME								= philo

BUILD_DIR							= build/

HEADER_DIR							= header/
HEADER_FILE							= philo.h

DIR									= src/
SRC									= 	philo.c	init.c	utils.c	time.c	routine.c	activity.c

OBJECTS								= $(SRC:%.c=$(BUILD_DIR)%.o)

GCC									= gcc -pthread -g3 -fsanitize=thread

CFLAGS								= -Wall -Werror -Wextra

RM									= rm -rf

$(BUILD_DIR)%.o:					$(DIR)%.c $(HEADER_DIR)*  Makefile 
										@mkdir -p $(@D)
										$(GCC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

all:								mkbuild lib $(HEADER_DIR) $(NAME)

mkbuild:							
										@mkdir -p build
										

$(NAME):							$(OBJECTS)
										@$(GCC) $(OBJECTS) -o $(NAME)
										@echo "$(PURPLE)[PHILO IS READY] $(END)"
										
clean:							
										@$(RM) $(OBJECTS)
										@$(RM) $(BUILD_DIR)
										@echo "$(GREEN)[CLEAN DONE] $(END)"

fclean:								clean
										@$(RM) $(NAME) 
										@echo "$(GREEN)[FCLEAN DONE] $(END)"

norm:								
										@echo "$(GREEN)[CHECKING NORMINETTE]$(END)"
										@norminette $(DIR) $(HEADER_DIR)

re:									fclean all
										@$(MAKE) all -silent
										@echo "$(PURPLE)[REMAKE DONE] $(END)"
				