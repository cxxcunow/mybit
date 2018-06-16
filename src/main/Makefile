TOPDIR=./../..

TARGET=mymain

LIBPATH=$(TOPDIR)/lib
EXEPATH=$(TOPDIR)/bin

CFLAGS+= -I$(TOPDIR)/include/crypto -I$(TOPDIR)/include/utils
LDFLAGS= -L$(LIBPATH) -lcrypto -lutils -fPIC
#dirs:=$(PWD)
dirs:=$(shell find . -maxdepth 1 -type d)
dirs:=$(basename $(patsubst ./%,%,$(dirs)))
dirs:=$(filter-out $(exclude_dirs),$(dirs))
include $(TOPDIR)/Makefile.env
