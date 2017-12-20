#include <linux/init.h>
#include <linux/module.h>
/* For the character driver support */
#include <linux/fs.h>
#include <linux/slab.h>

char *dma_ptr;

static int ex07_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

static ssize_t ex07_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

static ssize_t ex07_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return length;
}

static int ex07_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

/*To hold the file operations performed on this device*/
struct file_operations ex07_file_operations = {
    .owner   = THIS_MODULE,
    .open    = ex07_open,
    .read    = ex07_read,
    .write   = ex07_write,
    .release = ex07_close,
};

static int __init ex07_simple_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    /* Register with the kernal and indicate we are registering a character device driver */
    
    dma_ptr = kmalloc(64, GFP_KERNEL);
    printk(KERN_INFO "Allocated Memory using kmalloc..");
    register_chrdev(240/*major number*/,
		    "simple char drv" /*name of the driver*/,
		    &ex07_file_operations /*File operations*/);
    
    return 0;
}

static void __exit ex07_simple_module_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    /* Unregister the char device driver */
    unregister_chrdev(240, "simple char drv");
    
    kfree(dma_ptr);
    printk(KERN_INFO "freeing node");
}

module_init(ex07_simple_module_init);
module_exit(ex07_simple_module_exit);
MODULE_LICENSE("GPL");
