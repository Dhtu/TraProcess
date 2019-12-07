#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init_task.h>
// #include <linux/moduleparam.h>
// init function
static int tp_init(void)
{
    struct task_struct *task;
    task = NULL;
    // task = &init_task;
    // if(task==NULL)return 0;//prevent null reference and the noisy fix method relative to it.
    int running=0,interrupt=0,uninterrupt=0,stopped=0,traced=0,zombie=0,edead=0,tdead=0,wakekill=0,waking=0;
    printk("<tp> NAME                \t\tPID\tSTATE\tPPID\t");//table head
    // #define for_each_process(p) \
    // for (p = &init_task ; (p = next_task(p)) != &init_task ; )
    for_each_process(task)
    {
            printk("<tp> %-20s\t\t%d\t%ld\t%d\n",task->comm,task->pid, task->state,task->parent->pid);
            switch (task->state)
            {
            case TASK_RUNNING://if running state,running plus 1
                running++;
                break;
            case TASK_INTERRUPTIBLE://just like running
                interrupt++;
                break;
            case TASK_UNINTERRUPTIBLE://just like running
                uninterrupt++;
                break;
            case __TASK_STOPPED://just like running
                stopped++;
                break;
            case __TASK_TRACED://just like running
                traced++;
                break;
            case TASK_DEAD://just like running
                tdead++;
                break;
            case TASK_WAKEKILL://just like running
                wakekill++;
                break;
            case EXIT_ZOMBIE://just like running
                zombie++;
                break;
            
            case EXIT_DEAD://just like running
                edead++;
                break;
            case TASK_WAKING://just like running
                waking++;
                break;
            default:
                break;
            }
    }
    printk("<tp> running: \t%d\n",running);//print state count
    printk("<tp> interrupt: \t%d\n",interrupt);//dito
    printk("<tp> uninterrupt: \t%d\n",uninterrupt);//dito
    printk("<tp> stopped: \t%d\n",stopped);//dito
    printk("<tp> traced: \t%d\n",traced);//dito
    printk("<tp> zombie: \t%d\n",zombie);//dito
    printk("<tp> exit_dead: \t%d\n",edead);//dito
    printk("<tp> task_dead: \t%d\n",tdead);//dito
    printk("<tp> wakekill: \t%d\n",wakekill);//dito
    printk("<tp> waking: \t%d\n",waking);//dito
    return 0;
}
// clean function
static void tp_exit(void)
{
    printk("goodbye!\n");//goodbye honey!
}

// register
module_init(tp_init);  
module_exit(tp_exit);  

// GPL announcement
MODULE_LICENSE("GPL");
