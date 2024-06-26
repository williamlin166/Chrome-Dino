README
------

`SDL_bgi` is a multiplatform, SDL2-based `GRAPHICS.H` implementation.

Its name refers to BGI, the Borland Graphics Interface that was the
'de facto' standard in PC graphics back in DOS days; it was made
popular by Borland Turbo C/C++ compilers. I wrote `SDL_bgi` because
I wanted a simple to use but fast graphics library for my experiments
with fractals and cellular automata, using the BGI syntax I'm used to.

`SDL_bgi` is almost completely compatible with the BGI implementation
in Turbo C 2.01 and Borland C++ 1.0; for instance, it compiles and
runs the original `bgidemo.c`. `SDL_bgi` also provides nearly full
compatibility with another BGI implementation, WinBGIm (see links
below). One of the aims of `SDL_bgi` is the preservation of old
software written for BGI, but not only.

`SDL_bgi` provides graphics primitives, and is much easier to use than
plain SDL2. It should be especially useful for beginners, i.e. in
introductory programming courses. `SDL_bgi` is pretty fast and very
easy to use, and it also provides extensions for ARGB colours, mouse
support, vector fonts, and multiple windows. Native SDL2 functions can
be used alongside `SDL_bgi` functions. `SDL_bgi` can be used by C++
programs, too.

`SDL_bgi` should compile on any platform supported by SDL2; it has
been tested on GNU/Linux, MS Windows (MSYS2 + Mingw-w64, CodeBlocks,
Dev-C++), macOS (High Sierra and Catalina), and Raspberry Pi. A few
example programs are provided in the `test/` directory.

If you don't need BGI compatibility, I suggest that you check out
`SDL_gfx`, a graphics library that is more complete and more powerful
than `SDL_bgi`.

Links:

0. The SDL library:
   <https://www.libsdl.org/>

1. BGI on Wikipedia:
   <https://en.wikipedia.org/wiki/Borland_Graphics_Interface>

2. WinBGIm, another BGI Windows port:
   <http://www.cs.colorado.edu/~main/cs1300/doc/bgi/>

3. SDL_gfx, graphics drawing primitives and more:
   <https://sourceforge.net/projects/sdl2gfx/>

4. Xbgi, a BGI XLib port:
   <http://libxbgi.sourceforge.net/>

5. Borland Turbo C 2.01 online emulator:
   <https://archive.org/details/msdos_borland_turbo_c_2.01>

This library is licensed under the Zlib license; please see the
enclosed file LICENSE.

Brought to you by Guido Gonzato, PhD
<guido dot gonzato at gmail dot com>
