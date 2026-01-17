COMPILER = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

main: main.o chararray.o strarray.o
	$(COMPILER) $(CFLAGS) -o main $^

main.o: main.c chararray.h strarray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

strarray.o: strarray.c strarray.h chararray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

chararray.o: chararray.c chararray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm *.o
