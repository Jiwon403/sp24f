SRCS = main.c
LIBSRCS = open.c close.c put.c get.c 
TARG = kvs_static
TARG_DYNAMIC = kvs_dynamic

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
LARS2 = libkvs.so

all: 

static: $(TARG)

$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) -static

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

dynamic: $(TARG_DYNAMIC)

$(TARG_DYNAMIC) : $(OBJS) $(LARS2)
	$(CC) -o $(TARG_DYNAMIC) $(OBJS) $(LIBS) 

$(LARS2) : $(LOBJS)
	$(CC) -shared -o $(LARS2) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG) $(TARG_DYNAMIC) $(LARS2)
