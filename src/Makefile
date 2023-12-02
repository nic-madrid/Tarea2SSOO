CC = g++
CFLAGS = -Wall -std=c++11 $(shell pkg-config --cflags opencv4)
LDFLAGS = $(shell pkg-config --cflags --libs opencv4)

all: Prueba1

Prueba1: PruebaImagen.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f Prueba1