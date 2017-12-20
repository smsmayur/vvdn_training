path := /lib/modules/$(shell uname -r)/build

obj-m := ex02_simple_char_drv.o
obj-m := ex01.o

all:
	make -C $(path) M=$(PWD) modules
	make -C $(path) M=$(PWD) modules
clean:
	make -C $(path) M=$(PWD) clean
	make -C $(path) M=$(PWD) modules
