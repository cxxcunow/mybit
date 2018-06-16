TOPDIR=./../..

LIB=libutils.a

INCPATH=$(TOPDIR)/include/utils

LIBPATH=$(TOPDIR)/lib
CFLAGS= -I$(INCPATH)

dirs:=$(shell find . -maxdepth 1 -type d)
dirs:=$(basename $(patsubst ./%,%,$(dirs)))
dirs:=$(filter-out $(exclude_dirs),$(dirs))
#dirs:=$(pwd)
include $(TOPDIR)/Makefile.env
