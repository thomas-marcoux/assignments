#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/types.h>

struct	birthday
{
	int	day;
	int	month;
	int	year;
	struct list_head	list;
};

static	LIST_HEAD(birthday_list);

/* This function is called when the module is loaded. */
int simple_init(void) {

	struct	birthday	**t;
	struct	birthday	*ptr;
	int	i;
	int	nb_people = 5;

	printk(KERN_INFO "Loading Module\n");
	t = kmalloc(sizeof(*t) * nb_people, GFP_KERNEL);
	for (i = 0; i < nb_people; ++i)	{
		t[i] = kmalloc(sizeof(**t), GFP_KERNEL);
		t[i]->day = ((i+1) * 13) % 31 + 1;
		t[i]->month = ((i+1) * 3) % 12 + 1;
		t[i]->year = 1980 + i * 2;
		INIT_LIST_HEAD(&t[i]->list);
		list_add_tail(&t[i]->list, &birthday_list);
	}
	list_for_each_entry(ptr, &birthday_list, list)	{
		printk(KERN_INFO "Birthday : %d/%d/%d\n",
	ptr->day, ptr->month, ptr->year);
	}
       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	struct	birthday	*ptr, *next;

	list_for_each_entry_safe(ptr, next, &birthday_list, list) {
		list_del(&ptr->list);
		kfree(ptr);
	}
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

