COMPILER = gcc
CFLAGS = -Wall -Werror -g

main: main.o chararray.o
	$(COMPILER) $(CFLAGS) -o main $^

main.o: main.c chararray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

chararray.o: chararray.c chararray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm *.o
