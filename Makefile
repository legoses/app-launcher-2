INC_DIR=./include
SRC_DIR=./src
SRCS=$(SRC_DIR)/main.c

search:
	gcc $(SRCS) -o search -I $(INC_DIR)

clean:
	rm search
