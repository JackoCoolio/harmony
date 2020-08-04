CC=gcc
BINDIR=bin
SRC=src
OUTPUT=libharmony.a

INC=-Ivendor/glfw/include/ -Ivendor/glew/include/
LIB=-Lvendor/glfw/lib/ -Lvendor/glew/lib/ -lglfw3 -lgdi32 -lglew32 -lopengl32

OBJECTS = harmony_entry.o harmony_context.o harmony_timer.o
HARMONY_FLAGS=-DHARMONY_BUILD_WINDOWS

CFLAGS=-Wall $(INC) $(LIB) $(HARMONY_FLAGS)

all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	ar rcs $(BINDIR)/$@ $(OBJECTS)

harmony_entry.o: $(SRC)/harmony_entry.c $(SRC)/harmony_entry.h
	$(CC) -c $(SRC)/harmony_entry.c $(CFLAGS)

harmony_context.o: $(SRC)/harmony_context.c $(SRC)/harmony_context.h
	$(CC) -c $(SRC)/harmony_context.c $(CFLAGS)

harmony_timer.o: $(SRC)/harmony_timer.c $(SRC)/harmony_timer.h
	$(CC) -c $(SRC)/harmony_timer.c $(CFLAGS)

clean:
	rm $(OBJECTS) $(BINDIR)/$(OUTPUT)

