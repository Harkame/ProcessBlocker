GPP = g++
OPTIONS = -mwindows -static-libgcc -static-libstdc++

all:
	${GPP} ${OPTIONS} process_blocker.cpp -o InternalSecurity.exe
