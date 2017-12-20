#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/netdevice.h>
#include <linux/string.h>
#include <asm/uaccess.h>

static struct proc_dir_entry *proc_entry;

static int proc_show(struct seq_file *s, void *v)
{
    struct net_device *dev;

    for_each_netdev(&init_net, dev) {
	if(strcmp(dev->name, "lo")) {
	    seq_printf(s, "interface %s : %02x:%02x:%02x:%02x:%02x:%02x\n", dev -> name, dev -> dev_addr[0], dev -> dev_addr[1], dev -> dev_addr[2], dev -> dev_addr[3], dev -> dev_addr[4], dev -> dev_addr[5]);
	}
    }
    return 0;
}

static int proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, proc_show, NULL);
}

static const struct file_operations proc_fopen = {
    .owner   = THIS_MODULE,
    .open    = proc_open,
    .read    = seq_read,
    .release = single_release,
};


static __init int MAC_init(void)
{
    /* MAC_SYS is proc_file_name  */
    proc_entry = proc_create_data("MAC_SYS", S_IRUGO, NULL, &proc_fopen, NULL);
    if (!proc_entry)
	         return -ENOMEM;
         return 0;
}

static __exit void MAC_exit(void)
{
    if(proc_entry)
	remove_proc_entry("MAC_SYS", NULL);
}

module_init(MAC_init);
module_exit(MAC_exit);
MODULE_LICENSE("GP  L");
