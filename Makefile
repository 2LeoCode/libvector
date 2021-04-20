SHELL =		/bin/sh
NAME =		libvector.a

.SUFFIXES =	.c .o .h

SRCDIR =	src
INCDIR =	inc
LIBDIR =	lib
OBJDIR =	.obj

SRC =		$(foreach i,\
			assign\
			at\
			clear\
			erase\
			failure\
			init\
			insert\
			iterator\
			pop\
			push\
			reserve\
			resize\
			set\
			swap\
			value_0\
			value_1,\
			vector_$(i)$(word 1, $(.SUFFIXES)))
INC =		$(addsuffix $(word 3, $(.SUFFIXES)),\
			vector)
LIB =
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 2, $(.SUFFIXES)))

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -I $(INCDIR)
LCFLAGS =	$(addprefix -L, $(LIBDIR)) $(addprefix -l, $(LIB))

####    COLORS    ####
KNRM =		\x1B[0m
KRED =		\x1B[31m
KGRN =		\x1B[32m
KYEL =		\x1B[33m
KBLU =		\x1B[34m
KMAG =		\x1B[35m
KCYN =		\x1B[36m
KWHT =		\x1B[37m
######################

all: $(OBJDIR) $(NAME)
	@printf "$(KGRN)\`$(NAME)\` is up to date.\n"

$(OBJDIR):
	@printf "$(KYEL)➤ "
	mkdir $@
	@printf "$(KNRM)"

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@printf "$(KCYN)[  Linking  ]\n➤ "
	ranlib $@
	@printf "$(KNRM)"

$(OBJDIR)/%$(word 2, $(.SUFFIXES)): $(SRCDIR)/%$(word 1, $(.SUFFIXES)) $(addprefix $(INCDIR)/, $(INC))
	@printf "$(KMAG)[  Compiling  ]\n➤ "
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "➤ "
	ar rc $(NAME) $@
	@printf "$(KNRM)"

clean:
	@printf "$(KRED)➤ "
	rm -rf $(OBJDIR)
	@printf "$(KNRM)"

fclean: clean
	@printf "$(KRED)➤ "
	rm -f $(NAME)
	@printf "$(KNRM)"

re: fclean all
