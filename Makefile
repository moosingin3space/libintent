include config.mk

BUILDDIR=out
LIBNAME=libintent.a

HDR=libintent.h

_OBJ=
OBJ=$(patsubst %,$(BUILDDIR)/%,$(_OBJ))

all: $(BUILDDIR) $(BUILDDIR)/$(LIBNAME)


$(BUILDDIR): 
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.c $(HDR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILDDIR)/$(LIBNAME): $(OBJ)
	ar ru $@ $^
	ranlib $@

.PHONY: all clean

clean:
	rm -rf $(BUILDDIR)/*.o
