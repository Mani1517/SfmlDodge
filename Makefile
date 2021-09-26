window: compile window_linker
linux: compile linux_linker

compile:
	g++ -Iinclude/ -c src/*.cpp

window_linker:
	g++ *.o -Llib/ -o bin/win32/MyApp -lsfml-graphics -lsfml-system -lsfml-window

linux_linker:
	g++ *.o -L/usr/lib -o bin/linux/MyApp -lsfml-graphics -lsfml-system -lsfml-window