all: main

main:
	cl main.c
	del *.obj

clean:
	del *.exe
	del *.s