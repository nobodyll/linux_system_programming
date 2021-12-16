#src = $(wildcard ./*.c)
#obj = $(patsubst ./%.c, ./%.o, $(src))
#
#ALL:a.out
#
#a.out:$(obj)
#	gcc $^ -o $@
#
#$(obj):./%.o:./%.c
#	gcc $< -c -o $@
#
#clean:
#	-rm -rf $(obj) a.out
#
#.PHONY: ALL clean
#

src = $(wildcard *.c)
target = $(patsubst %.c, %, $(src))

ALL:$(target)

%:%.c
	gcc $< -o $@ -Wall -g

clean:
	-rm -rf $(target)

.PHONY: clean ALL
