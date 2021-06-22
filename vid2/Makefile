OBJS = $(patsubst src/%.c, obj/%.o, $(wildcard src/*.c))
CFLAGS = -Iinclude -g -ggdb `pkg-config --cflags glfw3 glew`
LIBS = `pkg-config --libs glfw3 glew` -lm
DEPS = $(wildcard include/*.h)
EXEC = main

obj/%.o: src/%.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
