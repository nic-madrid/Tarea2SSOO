# carga de librerias
CC = g++
CFLAGS = -Wall -std=c++11 -fopenmp $(shell pkg-config --cflags opencv4)
LDFLAGS = $(shell pkg-config --cflags --libs opencv4)

# nombre de los ejecutables
all: PS PT POMP

# compilacion de los ejecutables
## PS: Procesamiento Secuencial
PS: ProcesamientoSecuencial.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

## PT: Procesamiento Threads Threads
PT: ProcesamientoThreads.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

## PPMP: Procesamiento OpenMP
POMP: ProcesamientoOpenMP.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# limpieza de los ejecutables
clean:
	rm -f PS PT POMP
