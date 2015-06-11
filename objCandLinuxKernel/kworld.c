#include <linux/module.h>
#include <linux/kernel.h>

static int __init kworld_init()
{
printk("Hello init");
}

static void __exit kworld_exit()
{
printk("Exiting");
}

module_init(kworld_init);
module_exit(kworld_exit);

MODULE_AUTHOR("SIBI");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hands on Kernel Lets see how it goes");
