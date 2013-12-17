SOURCES := Character.cpp Pickup.cpp Player.cpp Weapon.cpp Room.cpp main.cpp
PROG := texDoom
CFLAGS := -Wall -Wextra -g
LDFLAGS :=

# -MMD generates dependencies while compiling
CFLAGS += -MMD
CC := g++

OBJFILES := $(SOURCES:.cpp=.o)
DEPFILES := $(SOURCES:.cpp=.d)

$(PROG) : $(OBJFILES)
	$(LINK.o) $(LDFLAGS) -o $@ $^

clean :
	rm -f $(PROG) $(OBJFILES) $(DEPFILES)

-include $(DEPFILES)


