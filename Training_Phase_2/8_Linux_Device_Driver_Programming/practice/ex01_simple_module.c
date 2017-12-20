#include <linux/init.h>
#include <linux/module.h>

/* start function */
int __init ex01_simple_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

/* end function (we can put any name to exit function) */ 
void __exit ex01_simple_module_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
}

/* macros calling of function */
module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);
