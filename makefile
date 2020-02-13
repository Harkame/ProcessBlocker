GPP = g++
OPTIONS = -mwindows

all:
	${GPP} ${OPTIONS} process_blocker.cpp -o myblocker.exe
