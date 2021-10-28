#pragma once


#if defined(__APPLE__)

#include <sys/systm.h>

#define LogDriverErr(fmt,...) printf("[*] " fmt "\n", ## __VA_ARGS__)
#define DbgPrintEx(a,b,fmt,...) printf("[*] " fmt, ## __VA_ARGS__)

#else

#include <linux/kernel.h>
#include <linux/sched.h>

#if defined(_DEBUG)
    #define DbgPrintEx(DRVRID, TRCLVL, fmt, args...) do { \
        printk( \
            KERN_DEBUG \
            "[*]  XD: {%5d > %5d > %5d} [%s:%d] <%s>: " fmt, \
            current->parent->tgid, current->tgid, task_pid_nr(current), \
            __FILE__, __LINE__, __func__, ##args \
        ); \
    } while (false)
#else
    #define DbgPrintEx(...) do {} while (false)
#endif

#endif
