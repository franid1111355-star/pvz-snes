ifeq ($(strip $(PVSNESLIB_HOME)),)
$(error "Please create an environment variable PVSNESLIB_HOME with path to its folder and restart application. (you can do it on windows with <setx PVSNESLIB_HOME "/c/pvsneslib"%> or with <export PVSNESLIB_HOME=/c/pvsneslib> on linux)")
endif

include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

.PHONY: bitmaps all

# ROM name
ROMNAME = pvz

# Source files
CFILES = main.c

# Object files
OBJFILES = $(CFILES:.c=.o)

all: bitmaps $(ROMNAME).sfc

clean:
	@rm -f *.o *.sfc *.sym

bitmaps:

$(ROMNAME).sfc: $(OBJFILES)
	$(LD) $(OBJFILES) -o $(ROMNAME).sfc
