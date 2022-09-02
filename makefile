2048player: driver.cpp check.o display.o moves.o undo.o instructions.o randominsert.o comparestates.o
	g++ -o 2048player driver.cpp check.o display.o moves.o undo.o instructions.o randominsert.o comparestates.o
# -o sets the name of the output file which g++ produces. The default output filename is a.out with this comment we are changing the a with what we want to keep.

check.o: check.cpp play2048.h
	g++ -c check.cpp
# -c tells gcc to compile a source file into a .o file. To compile files individually so that they can be linked later, we need -c

comparestates.o: comparestates.cpp play2048.h
	g++ -c comparestates.cpp

display.o: display.cpp play2048.h
	g++ -c display.cpp

moves.o: moves.cpp play2048.h
	g++ -c moves.cpp

undo.o: undo.cpp play2048.h
	g++ -c undo.cpp

instructions.o: instructions.cpp play2048.h
	g++ -c instructions.cpp

randominsert.o: randominsert.cpp play2048.h
	g++ -c randominsert.cpp

clean:
	rm -f *.o*out