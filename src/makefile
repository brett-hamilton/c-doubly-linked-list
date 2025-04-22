IDIR =../include
CC=cc
CFLAGS=-Wall

ODIR=obj

_DEPS = dllist.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = driver.o dllist.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
