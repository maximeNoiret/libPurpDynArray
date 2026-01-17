COMPILER = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined

libdynarray.a: chararray.o strarray.o
	ar rcs libpurpdynarray.a $^

main: main.o chararray.o strarray.o
	$(COMPILER) $(CFLAGS) -o main $^

main.o: main.c chararray.h strarray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

strarray.o: strarray.c strarray.h chararray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

chararray.o: chararray.c chararray.h
	$(COMPILER) $(CFLAGS) -c $< -o $@

install:
	cp libpurpdynarray.a /usr/local/lib/
	ranlib /usr/local/lib/libpurpdynarray.a
	cp chararray.h strarray.h /usr/local/include/

uninstall:
	rm -f /usr/local/lib/libpurpdynarray.a
	rm -f /usr/local/include/chararray.h /usr/local/include/strarray.h

clean:
	rm -f *.o *.a main
