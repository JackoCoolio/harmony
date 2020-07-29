CC=gcc
BINDIR=bin
SRC=src
OUTPUT=app.exe

INC=-Ivendor/glfw/include/ -Ivendor/glew/include/
LIB=-Lvendor/glfw/lib/ -Lvendor/glew/lib/ -lglfw3 -lgdi32 -lglew32 -lopengl32

CFLAGS=-Wall $(INC) $(LIB)

all: $(OUTPUT)

$(OUTPUT): main.o harmony_context.o
	$(CC) main.o harmony_context.o -o $(BINDIR)/$@ $(CFLAGS)

main.o: $(SRC)/main.c
	$(CC) -c $(SRC)/main.c $(CFLAGS)

harmony_context.o: $(SRC)/harmony_context.c $(SRC)/harmony_context.h
	$(CC) -c $(SRC)/harmony_context.c $(CFLAGS)

clean:
	rm main.o harmony_context.o $(BINDIR)/$(OUTPUT)

