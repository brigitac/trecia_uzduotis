CC = clang++
CXXFLAGS = -c -Wall -Weverything -Wno-c++98-compat -std=c++11

all: main.o galbalas.o sukurimas.o studentas.o
	$(CC) $^
main.o: main.cpp galbalas.h failai.h studentas.h sukurimas.h
	$(CC) $(CXXFLAGS) $<
galbalas.o: galbalas.cpp galbalas.h
	$(CC) $(CXXFLAGS) $<
sukurimas.o: sukurimas.cpp sukurimas.h
	$(CC) $(CXXFLAGS) $<
studentas.o: studentas.cpp studentas.h
	$(CC) $(CXXFLAGS) $<
clean:
	rm -f *.o $@
