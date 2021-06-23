#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAX");
MODULE_DESCRIPTION("Simple test module");
MODULE_VERSION("0.01");

static int __init test_init(void) {
    printk(KERN_DEBUG "Hello World!");
    return 0;
}

static void __exit test_exit(void) {
    printk(KERN_DEBUG "Goodbye!"); 
}

module_init(test_init);
module_exit(test_exit);
