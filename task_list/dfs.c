#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>

#include <linux/sched.h>

void	depth_first_search(struct list_head *head, int depth)	{
  struct	list_head	*list;
  struct	task_struct	*task;

  list_for_each(list, head) {
    task = list_entry(list, struct task_struct, sibling);
    printk(KERN_INFO "%d -> %s [%lu]", task->pid, task->comm, task->state);
    depth_first_search(&task->children, depth + 1);
  }
}

int simple_init(void) {
  printk(KERN_INFO "Loading Module\n");
  depth_first_search(&init_task.children, 0);
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
