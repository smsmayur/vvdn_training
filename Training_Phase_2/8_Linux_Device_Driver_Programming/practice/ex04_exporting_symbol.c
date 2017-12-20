#include <linux/init.h>
#include <linux/module.h>

int ex04_simple_module_function(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

EXPORT_SYMBOL(ex04_simple_module_function);

int __init ex04_simple_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

/* end function (we can put any name to exit function) */ 
void __exit ex04_simple_module_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

/* macros calling of function */
module_init(ex04_simple_module_init);
module_exit(ex04_simple_module_exit);
