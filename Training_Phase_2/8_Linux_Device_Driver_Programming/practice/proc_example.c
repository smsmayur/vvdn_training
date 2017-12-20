#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/kernel.h>

struct proc_dir_entry *tlc_proc_a;

static ssize_t tlc_proc_a_read(struct file *fp, char *buf, size_t len, loff_t *off)
{
    static int finished = 0;

    if(finished) {
	finished = 0;
	return 0;
    }
    finished = 1;
    strcpy(buf, "The Linux Channel :: Hello World!\n");
    return strlen(buf);

}

static struct file_operations tlc_proc_a_fops = {.owner = THIS_MODULE, .read = tlc_proc_a_read, };

static int hello_init(void)
{
    tlc_proc_a = proc_create("tlc_proc_a", 0444, NULL, &tlc_proc_a_fops);
    if (tlc_proc_a == NULL)
	printk(KERN_ALERT "could not initialize %s\n", "tlc_proc_a");

    return 0;
}

static void hello_exit(void)
{
    remove_proc_entry("tlc_proc_a", NULL);
}

module_init(hello_init);
module_exit(hello_exit);

