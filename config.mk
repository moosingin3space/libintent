# Compiler configuration
CC=gcc
LD=gcc

# libbsd
LIBBSD_CFLAGS=$(shell pkg-config --cflags libbsd-overlay)
LIBBSD_DIR=
LIBBSD_LIB=$(shell pkg-config --libs libbsd-overlay)

# All libraries
LIB_CFLAGS=$(LIBBSD_CFLAGS) 
LIBDIRS=$(LIBBSD_DIR) 
LIBS=$(LIBBSD_LIB) -lm

CFLAGS=-Wall -Werror $(LIB_CFLAGS)
LDFLAGS=$(LIBS)

