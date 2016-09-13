ifeq ($(shell uname -s),Darwin)
@echo 'Building for MacOSX'
PLATFORM=OSX
else ifeq($(shell uname -o),Android)
@echo 'Building for Android'
PLATFORM=Android
else ifeq($(shell uname -o),Cygwin)
@echo 'Building for Cygwin'
PLATFORM=CYGWIN
else
@echo 'Environment not recognised (assuming defaults)'
PLATFORM=Unknown
endif
CC?=clang
SOURCEDIR=./SOURCE
SOURCE=$(SOURCEDIR)/*.c
INCLUDEDIR=./INCLUDE
OBJECTSDIR=./OBJECTS
OBJECTS=$(SOURCE:.c=.o)
BINDIR=./BIN
PORTSDIR=/opt/local
ifeq ($(BUILD),SDL2)
LINKERFLAGS=-llua,-lsdl2,-lgl,-lglew,
else ifeq ($(BUILD),GLFW3)
LINKERFLAGS=-llua,-lglfw3,-lIL -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
else
@echo "No build type specified; please specify a library to build against with either \'BUILD=SDL2\' or \'BUILD=GLFW3\'."
endif
#LINKERFLAGS=-llua,-lsdl2,-lgl,-lglew, #removed -lconfig
MOSTFLAGS=-I$(INCLUDEDIR) -I$(PORTSDIR)/include -I/usr/local/include -L$(PORTSDIR)/lib -L/usr/local/lib -Wl,$(LINKERFLAGS) -arch=x86_64 -mmacosx-version-min=10.9
ifeq ($(VERBOSE),on)
FLAGS=$(MOSTFLAGS) -v
else
FLAGS=$(MOSTFLAGS)
endif
#FLAGS=-I$(INCLUDEDIR) -I$(PORTSDIR)/include -L$(PORTSDIR)/lib -v -Wl,$(LINKERFLAGS) -arch=x86_64 -mmacosx-version-min=10.9
TARGET=$(BINDIR)/$(PLATFORM)

#*.o:
#	$(CC) $(FLAGS) $(SOURCEDIR)/$@ -o 

all: #$(OBJECTSDIR)/OBJECTS
	#sep
	$(CC) $(FLAGS) $(SOURCEDIR)/*.c -o $(OUTPUT)
	
run: all
	./$(OUTPUT) #--configfilename=fullscreen.ini
	
default: all
	rm default.ini
	./$(OUTPUT)

fullscreen: all
	./$(OUTPUT) --configfilename=fullscreen.ini
	
clean: 
	
