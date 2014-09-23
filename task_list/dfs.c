#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>

#include <linux/sched.h>

struct	task_struct	*task;
struct	list_head	*list;

int simple_init(void) {
  printk(KERN_INFO "Loading Module\n");
  list_for_each(list, &init_task->children) {
    task = list_entry(list, struct task_struct, sibling);
  }
  return 0;
}

void simple_exit(void) {
  printk(KERN_INFO "Removing Module\n");
}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");
