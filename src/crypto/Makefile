TOPDIR=./../..

LIB=libcrypto.a

INCPATH=$(TOPDIR)/include/utils
INCPATH+=-I$(TOPDIR)/include/crypto
LIBPATH=$(TOPDIR)/lib
CFLAGS= -I$(INCPATH)
#dirs:=$(PWD)
dirs:=$(shell find . -maxdepth 1 -type d)
dirs:=$(basename $(patsubst ./%,%,$(dirs)))
dirs:=$(filter-out $(exclude_dirs),$(dirs))
include $(TOPDIR)/Makefile.env
