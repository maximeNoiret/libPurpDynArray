COMPILER = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address,undefined
COMPILE_OBJECT = $(COMPILER) $(CFLAGS) -c $< -o $@

libdynarray.a: chararray.o strarray.o
	ar rcs libpurpdynarray.a $^

main: main.o chararray.o strarray.o strmap.o
	$(COMPILER) $(CFLAGS) -o main $^

main.o: main.c chararray.h strarray.h strmap.h
	$(COMPILE_OBJECT)

strmap.o: strmap.c strmap.h chararray.h
	$(COMPILE_OBJECT)

strarray.o: strarray.c strarray.h chararray.h
	$(COMPILE_OBJECT)

chararray.o: chararray.c chararray.h
	$(COMPILE_OBJECT)

install:
	cp libpurpdynarray.a /usr/local/lib/
	ranlib /usr/local/lib/libpurpdynarray.a
	cp chararray.h strarray.h /usr/local/include/

uninstall:
	rm -f /usr/local/lib/libpurpdynarray.a
	rm -f /usr/local/include/chararray.h /usr/local/include/strarray.h

clean:
	rm -f *.o *.a main
