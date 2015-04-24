include config.mk

BUILDDIR=out
LIBNAME=libintent.a

HDR=stringptr.h libintent.h

_OBJ=stringptr.o
OBJ=$(patsubst %,$(BUILDDIR)/%,$(_OBJ))

all: $(BUILDDIR) $(BUILDDIR)/$(LIBNAME)


$(BUILDDIR): 
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.c $(HDR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILDDIR)/$(LIBNAME): $(OBJ)
	$(LD) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: all clean

clean:
	rm -rf $(BUILDDIR)/*.o
