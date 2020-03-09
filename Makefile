CC=g++
CFLAGS=-Wall -std=c++17
CPP_SRCS=*.h *.cpp

HC=ghc
HFLAGS=-no-keep-o-files -no-keep-hi-files

cpp : $(CPP_SRCS)
	$(CC) $(CPP_SRCS) -o cat_theory.o $(CFLAGS)

hs : $(HS_SRCS)
	$(HC) --make main.hs $(HFLAGS)

all : cpp hs

clean :
	rm *.o *.hi main