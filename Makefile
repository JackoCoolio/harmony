CC=gcc
BINDIR=bin
SRC=src
OUTPUT=libharmony.a

INC=-Ivendor/glfw/include/ -Ivendor/glew/include/ -Ivendor/lodepng/include/ -Ivendor/cglm/include/
LIB=-Lvendor/glfw/lib/ -Lvendor/glew/lib/ -Lvendor/cglm/lib/ -lcglm -lglfw3 -lgdi32 -lopengl32

OBJECTS = harmony_entry.o harmony_context.o harmony_timer.o harmony_renderer.o harmony_shader.o harmony_file.o harmony_log.o harmony_texture.o harmony_batch.o harmony_buffer.o harmony_sprite.o glew.o lodepng.o
HARMONY_FLAGS=-DHARMONY_BUILD_WINDOWS

CFLAGS=-Wall -Wno-missing-braces $(INC) $(LIB) $(HARMONY_FLAGS) -DGLEW_STATIC

CONFIG := release

.PHONY: all
all: $(CONFIG)

.PHONY: release
release: $(OUTPUT)

.PHONY: debug
debug: CFLAGS += -g
debug: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	ar rcs $(BINDIR)/$@ $(OBJECTS)

harmony_entry.o: $(SRC)/harmony_entry.c $(SRC)/harmony_entry.h
	$(CC) -c $(SRC)/harmony_entry.c $(CFLAGS)

harmony_context.o: $(SRC)/harmony_context.c $(SRC)/harmony_context.h
	$(CC) -c $(SRC)/harmony_context.c $(CFLAGS)

harmony_timer.o: $(SRC)/harmony_timer.c $(SRC)/harmony_timer.h
	$(CC) -c $(SRC)/harmony_timer.c $(CFLAGS)

harmony_renderer.o: $(SRC)/harmony_renderer.c $(SRC)/harmony_renderer.h
	$(CC) -c $(SRC)/harmony_renderer.c $(CFLAGS)

harmony_shader.o: $(SRC)/harmony_shader.c $(SRC)/harmony_shader.h
	$(CC) -c $(SRC)/harmony_shader.c $(CFLAGS)

harmony_file.o: $(SRC)/harmony_file.c $(SRC)/harmony_file.h
	$(CC) -c $(SRC)/harmony_file.c $(CFLAGS)

harmony_log.o: $(SRC)/harmony_log.c $(SRC)/harmony_log.h
	$(CC) -c $(SRC)/harmony_log.c $(CFLAGS)

harmony_texture.o: $(SRC)/harmony_texture.c $(SRC)/harmony_texture.h
	$(CC) -c $(SRC)/harmony_texture.c $(CFLAGS)

harmony_batch.o: $(SRC)/harmony_batch.c $(SRC)/harmony_batch.h
	$(CC) -c $(SRC)/harmony_batch.c $(CFLAGS)

harmony_buffer.o: $(SRC)/harmony_buffer.c $(SRC)/harmony_buffer.h
	$(CC) -c $(SRC)/harmony_buffer.c $(CFLAGS)

harmony_sprite.o: $(SRC)/harmony_sprite.c $(SRC)/harmony_sprite.h
	$(CC) -c $(SRC)/harmony_sprite.c $(CFLAGS)

# harmony_vector.o: $(SRC)/harmony_vector.c $(SRC)/harmony_vector.h
# 	$(CC) -c $(SRC)/harmony_vector.c $(CFLAGS)

glew.o:
	$(CC) -c vendor/glew/src/glew.c -Ivendor/glew/include -DGLEW_STATIC

lodepng.o:
	$(CC) -c vendor/lodepng/src/lodepng.c -Ivendor/lodepng/include

clean:
	rm $(OBJECTS) $(BINDIR)/$(OUTPUT)

