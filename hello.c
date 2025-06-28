#include <linux/module.h> // Provides macros like module license and module handling
#include <linux/kernel.h> // Gives us prink() which is the kernels version of printf
#include <linux/init.h> // provides macros like __init and __exit for setup/cleanup


static char *name = "World"; // Declares a kernel variable that stores a string. Defaults to world
module_param(name, charp, 0000);
// Tells the kernel this variable is a parameter. The charp mean it's a string pointer.
// File permissions for 
// 
MODULE_PARM_DESC(name, "The name to greet");


static int __init hello_start(void)
{
    printk(KERN_INFO "Hello %s! Kernel module loaded.\n", name);
    return 0;
}

static void __exit hello_end(void)
{
    printk(KERN_INFO "Goodbye %s! Kernel module unloaded.\n", name);
}

module_init(hello_start); // hello_start when the module is loaded
module_exit(hello_end); // hello_end when the module is removed

MODULE_LICENSE("GPL"); // Tells the kernel you're not using proprietary code.
MODULE_AUTHOR("Felipe"); // Author/descriptions show up when you run modeinfo hello.ko
MODULE_DESCRIPTION("A parameterized Hello World kernel module.");