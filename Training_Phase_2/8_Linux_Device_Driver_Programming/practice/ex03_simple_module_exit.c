#include <linux/init.h>
#include <linux/module.h>

/* end function (we can put any name to exit function) */ 
void __exit ex03_simple_module_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

module_exit(ex03_simple_module_exit);
