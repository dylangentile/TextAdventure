CC = g++
CFLAGS = -Wall -g -std=c++11


INCLUDES = -I../include
LFLAGS = 
LIBS = 
#-lmylib -lm

SRCS = textGame.cpp player.cpp game.cpp room.cpp objectMap.cpp 


OBJS = $(SRCS:.c=.o)

MAIN = textGame

.PHONY: depend clean

all:    $(MAIN)
		$(MESSAGE)

$(MESSAGE):
		ifeq($(OS),Windows_NT) 
			ECHO Compiler named genius has been compiled, you are welcome.
		else  
			@echo  Compiler named genius has been compiled, You are welcome
		endif	

$(MAIN): $(OBJS) 
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ $(MAIN)
		$(RM) -r *.dSYM
		$(RM) *.exe 

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
