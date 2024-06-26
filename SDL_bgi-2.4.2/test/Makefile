# Makefile for test SDL_bgi programs
# Please note that f90_test.f90 is not included

# C compiler: gcc or clang
CC = gcc

# Detect the platform: GNU/Linux, Darwin (macOS), Mingw-w64
PLATFORM := $(shell uname -s)

# GNU/Linux
ifeq ($(PLATFORM),Linux)
CFLAGS = -std=gnu99 -O2 -g -I. -I/usr/include/SDL2 -Wall 
LIBS = -lSDL_bgi -lSDL2
endif

# macOS - tested on Catalina
ifeq ($(PLATFORM),Darwin)
CFLAGS = -std=gnu99 -O2 -g -I. -I/usr/local/include
LIBS = -lSDL_bgi -lSDL2
endif

# Latest MSYS2 + Mingw-w64
msys := $(findstring MSYS, $(PLATFORM))
ifeq ($(msys),MSYS)
CFLAGS = -std=gnu99 -O2 -g -I. -I/mingw64/include -I/mingw64/include/SDL
# -mconsole = open a console alongside the program
# -mwindows = Windows-only program (no console)
LIBS = -lmingw32 -L/mingw64/bin -lSDL_bgi -lSDL2main -lSDL2 # -mwindows
endif

PROGRAMS = boo buffers cellular dla fern floodfilltest fonts \
           hopalong life linebuffers kaleido mandelbrot mousetest \
	   multiwin plasma psychedelia sdlbgidemo setpalette simple \
	   turtledemo

all: $(PROGRAMS)

# bgidemo does not compile by default in MSYS2 because of the main()
# declaration. Change it as: int main (int argc, char *argv[])

WGET := $(shell which wget)

bgidemo: bgidemo.c
ifeq ($(msys),MSYS)
	# fix wrong main() definition
	sed -i 's/main()/main(int argc, char *argv[])/' bgidemo.c
endif
	$(CC) $(CFLAGS) -I. -o bgidemo bgidemo.c $(LIBS) -lm

bgidemo.c:
ifdef WGET
	wget http://libxbgi.sourceforge.net/bgidemo.c
else
	$(info Could not find 'wget', can't download bgidemo.c)
endif

boo: boo.c 
	$(CC) $(CFLAGS) -o boo boo.c $(LIBS)

buffers: buffers.c 
	$(CC) $(CFLAGS) -o buffers buffers.c $(LIBS)

cellular: cellular.c 
	$(CC) $(CFLAGS) -o cellular cellular.c $(LIBS)

dla: dla.c 
	$(CC) $(CFLAGS) -o dla dla.c $(LIBS)

fern: fern.c 
	$(CC) $(CFLAGS) -o fern fern.c $(LIBS)

floodfilltest: floodfilltest.c 
	$(CC) $(CFLAGS) -o floodfilltest floodfilltest.c $(LIBS)

fonts: fonts.c 
	$(CC) $(CFLAGS) -o fonts fonts.c $(LIBS)

hopalong: hopalong.c 
	$(CC) $(CFLAGS) -o hopalong hopalong.c $(LIBS) -lm

life: life.c 
	$(CC) $(CFLAGS) -o life life.c $(LIBS)

linebuffers: linebuffers.c 
	$(CC) $(CFLAGS) -o linebuffers linebuffers.c $(LIBS)

kaleido: kaleido.c 
	$(CC) $(CFLAGS) -o kaleido kaleido.c $(LIBS)

mandelbrot: mandelbrot.c 
	$(CC) $(CFLAGS) -o mandelbrot mandelbrot.c $(LIBS)

mousetest: mousetest.c 
	$(CC) $(CFLAGS) -o mousetest mousetest.c $(LIBS)

multiwin: multiwin.c 
	$(CC) $(CFLAGS) -o multiwin multiwin.c $(LIBS)

plasma: plasma.c 
	$(CC) $(CFLAGS) -o plasma plasma.c $(LIBS) -lm

psychedelia: psychedelia.c 
	$(CC) $(CFLAGS) -o psychedelia psychedelia.c $(LIBS) -lm

sdlbgidemo: sdlbgidemo.c 
	$(CC) $(CFLAGS) -I. -o sdlbgidemo sdlbgidemo.c $(LIBS) -lm

setpalette: setpalette.c 
	$(CC) $(CFLAGS) -o setpalette setpalette.c $(LIBS)

simple: simple.c 
	$(CC) $(CFLAGS) -o simple simple.c $(LIBS)

turtledemo: turtledemo.c turtle.c 
	$(CC) $(CFLAGS) -o turtledemo turtledemo.c turtle.c $(LIBS) -lm

clean:
	rm -rf $(PROGRAMS) bgidemo* a.out *o f90_test *dSYM

# --- end of Makefile
