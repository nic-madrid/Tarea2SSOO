CC = g++
CFLAGS = -Wall -std=c++11 $(shell pkg-config --cflags opencv4)
LDFLAGS = $(shell pkg-config --cflags --libs opencv4)

all: ProcesamientoSecuencial

ProcesamientoSecuencial: PruebaImagen.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f ProcesamientoSecuencial