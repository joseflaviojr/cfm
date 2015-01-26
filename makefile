CC=gcc
CXX=g++
RM=rm -f

SRCS=CFM.cpp Aplicacao.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: CFM

CFM: CFM.o Aplicacao.o
	$(CXX) CFM.o Aplicacao.o -o CFM

CFM.o: CFM.h CFM.cpp

Aplicacao.o: Aplicacao.cpp

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) CFM
