#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/kernel.h>

static int hello_proc_show(struct seq_file *m, void *v) {
    seq_printf(m, "P5 : Hello proc!\n");
    return 0;
}

static int hello_proc_open(struct inode *inode, struct  file *file) {
    return single_open(file, hello_proc_show, NULL);
}

static const struct file_operations hello_proc_fops = {
    .owner = THIS_MODULE,
    .open = hello_proc_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

static int hello_proc_init(void) {
    proc_create("hello_proc", 0, NULL, &hello_proc_fops);
    printk("P5 : Process hello proc created");
    return 0;
}

static void hello_proc_exit(void) {
    remove_proc_entry("hello_proc", NULL);
    printk("Process hello proc removed");
}

MODULE_LICENSE("GPL");
module_init(hello_proc_init);
module_exit(hello_proc_exit);
