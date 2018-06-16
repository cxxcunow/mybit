TOPDIR=.

exclude_dirs= include  bin  lib

dirs:=$(shell find . -maxdepth 1 -type d)
dirs:=$(basename $(patsubst ./%,%,$(dirs)))
dirs:=$(filter-out $(exclude_dirs),$(dirs))
include $(TOPDIR)/Makefile.env
