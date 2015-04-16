CFLAGS= -O -Wall
CC=gcc
INSTALL=install

LIBS=libmii.o

all: mii-diag mii-diag-udeb

mii-diag:
	$(CC) $(CFLAGS) -Wstrict-prototypes -O mii-diag.c -DLIBMII \
				libmii.c -o mii-diag

mii-diag-udeb:
	$(CC) -Os -Wstrict-prototypes -O mii-diag.c -o mii-diag
clean:
	rm -f *.o mii-diag mii-diag-udeb *~

install-mii-diag:
	mkdir -p $(DESTDIR)/usr/sbin
	$(INSTALL) mii-diag $(DESTDIR)/usr/sbin

install-mii-diag-udeb:
	mkdir -p $(DESTDIR)/usr/sbin
	$(INSTALL) mii-diag-udeb $(DESTDIR)/usr/sbin/mii-diag
	
install: all install-mii-diag
