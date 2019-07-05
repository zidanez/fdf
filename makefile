NAME			= fdf

SOURSE_DIRS		:= src src/draw src/control src/init

# FLAGS			= -Wall -Werror -Wextra

framework		= -L minilibx -lmlx -framework OpenGL -framework AppKit -L libft -lft

SEARCH_WILDCARDS:= $(addsuffix /*.c, $(SOURSE_DIRS))

OBJECTS			= $(notdir $(patsubst %.c,%.o, $(wildcard $(SEARCH_WILDCARDS))))

GNL				= libft/get_next_line.c

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(GNL) $^ -o $@ $(framework)

VPATH := $(SOURSE_DIRS)

%.o: %.c
	gcc $(FLAGS) $(compile_flags) -c $<

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
