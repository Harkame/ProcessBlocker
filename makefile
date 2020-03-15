GPP = g++
OPTIONS = -std=c++17 -O3 -W -Wall -Weffc++ -Werror -pedantic -mwindows -static-libgcc -static-libstdc++

all:
	${GPP} ${OPTIONS} src/pb.cpp -o pb.exe
