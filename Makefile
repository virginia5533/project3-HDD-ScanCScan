#Virginia Vaughan
#Makefile
CC= g++
DEBUG = -g
CXXFLAGS = $(DEBUG) -c -Wall -std=c++11
LDLIBS =

TARGET = main

SOURCES = \
	main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(Target): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LDLIBS)
	./main
.cpp.o:
	$(CC) $(CXXFLAGS) $< -o $@

.PHONY : all $(TARGET)

clean:
	rm -f $(OBJECTS)

clobber:clean
	rm -f $(TARGET)
