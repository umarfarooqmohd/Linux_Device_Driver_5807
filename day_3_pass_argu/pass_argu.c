#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/init.h>

int valueETX ,arr_valueETX[4];
char *nameETX;
int cb_valueETX = 0;

module_param(valueETX, int, S_IRUSR|S_IWUSR);
module_param(nameETX, charp, S_IRUSR|S_IWUSR);
module_param_array(arr_valueETX, int, NULL, S_IRUSR|S_IWUSR);


int notify_param(const char* val,const struct kernel_param *kp){
	int res = param_set_int(val, kp);
	if(res == 0){
		printk(KERN_INFO "callback function.../ \n");
		printk(KERN_INFO "new value of  cbvalueETX %d \n");
		return 0;
}
	return -1;

}


const struct kernel_param_ops my_param_ops =
{
	.set = &notify_param,
	.get = &param_get_int,
};

module_param_cb(cb_valueETX, &my_param_ops, &cb_valueETX, S_IRUGO|S_IWUSR);


static int __init helloworld_init(void)
{
	int i;
	printk(KERN_INFO "valueETX = %d \n",valueETX);
	printk(KERN_INFO "cb_valueETX = %d \n",cb_valueETX);
	printk(KERN_INFO "nameETX = %c \n",nameETX);
	for (i = 0; i < (sizeof arr_valueETX / sizeof(int)); i++){
		  printk(KERN_INFO "Arr_value[%d] = %d\n", i, arr_valueETX[i]);
	}
	printk(KERN_INFO "kernel module inserted successfully...");
      return 0;
}

static void __exit helloworld_exit(void){

		printk(KERN_INFO "kernel module removed successfully...");
	}

module_init(helloworld_init);
module_exit(helloworld_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("UMAR FAROOQ");
MODULE_DESCRIPTION("A simple hello world driver");
MODULE_VERSION("1.0");
