#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>

dev_t far = MKDEV(255 , 1);                       


static int __init majmin_init(void){
	register_chrdev_region(far, 1, "Umar_farooq");
	printk(KERN_INFO "major = %d minor = %d\n",MAJOR(far),MINOR(far));
	printk(KERN_INFO "kernel module Inserted Successfully.");
	return 0;
}

static void __exit majmin_exit(void){
	unregister_chrdev_region(far,1);
	printk(KERN_INFO "kernal module removed successfully");
}


module_init(majmin_init);
module_exit(majmin_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("UMAR_FAROOQ");
MODULE_DESCRIPTION("Simple linux driver (Statically allocating the Major and Minor number)");
MODULE_VERSION("1.0");
