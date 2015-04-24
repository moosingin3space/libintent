# Compiler configuration
CC=gcc
LD=gcc

# libbsd
LIBBSD_CFLAGS=$(shell pkg-config --cflags libbsd-overlay)
LIBBSD_DIR=
LIBBSD_LIB=$(shell pkg-config --libs libbsd-overlay)

# zeromq, czmq
ZEROMQ_CFLAGS=
ZEROMQ_DIR=
ZEROMQ_LIB=-lzmq -lczmq

# All libraries
LIB_CFLAGS=$(LIBBSD_CFLAGS) $(ZEROMQ_CFLAGS)
LIBDIRS=$(LIBBSD_DIR) $(ZEROMQ_DIR)
LIBS=$(LIBBSD_LIB) $(ZEROMQ_LIB) -lm

CFLAGS=-Wall -Werror $(LIB_CFLAGS)
LDFLAGS=$(LIBS)

