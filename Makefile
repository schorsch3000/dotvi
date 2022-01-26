.PHONY: format format_c all

all: fnmatchfilter

fnmatchfilter: fnmatchfilter.c
	gcc -Os -o fnmatchfilter fnmatchfilter.c


format: format_c

format_c:
	clang-format fnmatchfilter.c | sponge fnmatchfilter.c
