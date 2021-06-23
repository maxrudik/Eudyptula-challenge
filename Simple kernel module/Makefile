obj-m += test_module.o

all:
	make -C /lib/modules/5.8.0-43-generic/build M=$(PWD) modules
clean:
	make -C /lib/modules/5.8.0-43-generic/build M=$(PWD) clean
