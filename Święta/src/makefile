IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=# tu dodać biblioteki (-lm)

_DEPS = #tu dodać piki nagłówkowe z biblioteki include
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = # tu dodać pliki z końcówką .o (hellomake.o hellofunc.o )
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sscanf_testy: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	