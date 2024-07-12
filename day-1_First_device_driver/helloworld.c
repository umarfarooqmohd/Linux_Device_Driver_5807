#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

static int __init helloworld_init(void){

	pr_info("hi im Umar Farooq\n");
	pr_info("this is my first program\n");
	pr_info("kernal module inserted successfully\n");
	return 0;
}

static void __exit helloworld_exit(void){

	pr_info("module removed successfully\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("UMAR FAROOQ");
MODULE_DESCRIPTION("first device driver program");
MODULE_VERSION("2.1.0");
