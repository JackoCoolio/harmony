CC=gcc
BINDIR=bin
SRC=src
OUTPUT=app.exe

INC=-Ivendor/glfw/include/ -Ivendor/glew/include/
LIB=-Lvendor/glfw/lib/ -Lvendor/glew/lib/ -lglfw3 -lgdi32 -lglew32 -lopengl32

CFLAGS=-Wall $(INC) $(LIB)

all: $(OUTPUT)

$(OUTPUT): main.o harmony_context.o harmony_node.o harmony_linked_list.o
	$(CC) main.o harmony_context.o harmony_node.o harmony_linked_list.o -o $(BINDIR)/$@ $(CFLAGS)

main.o: $(SRC)/main.c
	$(CC) -c $(SRC)/main.c $(CFLAGS)

harmony_context.o: $(SRC)/harmony_context.c $(SRC)/harmony_context.h
	$(CC) -c $(SRC)/harmony_context.c $(CFLAGS)

harmony_node.o: $(SRC)/harmony_node.c $(SRC)/harmony_node.h harmony_linked_list.o
	$(CC) -c $(SRC)/harmony_node.c $(CFLAGS)

harmony_linked_list.o: $(SRC)/harmony_linked_list.c $(SRC)/harmony_linked_list.h
	$(CC) -c $(SRC)/harmony_linked_list.c $(CFLAGS)

clean:
	rm main.o harmony.o harmony_context.o harmony_linked_list.o harmony_node.o $(BINDIR)/$(OUTPUT)

