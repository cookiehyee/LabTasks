#	Makefile for the NameAge program

#	Define compiler and link editor
CC	= gcc 
LD	= $(CC) 

#	Define CLAGS to check compilaton warnings
CFLAGS	= -Wall

#	Define .c files
CFILES	= \
        NameAge.c\
        Person.c\
        mystrings.c

#	Define of .o files
OFILES	= $(CFILES:%.c=%.o)

#	Build the executable using the .o files and optimize
NameAge:	$(OFILES)
	$(LD) -O6 $(CFLAGS) -o $@ $(OFILES)

#	Use defaults to build the .o files
NameAge.o:      NameAge.c Person.h

Person.o:       Person.c Person.h	

mystrings.o:    mystrings.c mystrings.h

#	Target clean to delete all .o files related to the project
clean:
	rm -f *.o *.bak *~
