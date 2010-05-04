#
# Created by gmakemake (Darwin May  4 2010) on Tue May  4 15:23:27 2010
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c

########## Flags from header.mak

CXXFLAGS = -ggdb -Wall -ansi -pedantic -lm -lglut -lGLU -lGL
CFLAGS = -ggdb -Wall -ansi -pedantic
CLIBFLAGS = -lm
CCLIBFLAGS = 

########## End of flags from header.mak


CPP_FILES =	bloodparticlesystem.cpp main.cpp particle.cpp particleforcegen.cpp
C_FILES =	
S_FILES =	
H_FILES =	bloodparticlesystem.h foundation.h main.h particle.h particleforcegen.h pengine.h precision.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	bloodparticlesystem.o particle.o particleforcegen.o 

#
# Main targets
#

all:	main 

main:	main.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o main main.o $(OBJFILES) $(CCLIBFLAGS)

#
# Dependencies
#

bloodparticlesystem.o:	GL/glut.h bloodparticlesystem.h foundation.h particle.h particleforcegen.h pengine.h precision.h
main.o:	GL/glut.h bloodparticlesystem.h foundation.h main.h particle.h particleforcegen.h pengine.h precision.h
particle.o:	foundation.h particle.h precision.h
particleforcegen.o:	foundation.h particle.h particleforcegen.h precision.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm $(OBJFILES) main.o core 2> /dev/null

realclean:        clean
	-/bin/rm -rf main 
