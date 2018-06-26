// golden
// 6/12/2018
//

#ifndef _PTRACE_H
#define _PTRACE_H

#include <ps4.h>
#include "kdbg.h"

// taken from ptrace.h

#define	PT_TRACE_ME	0	/* child declares it's being traced */
#define	PT_READ_I	1	/* read word in child's I space */
#define	PT_READ_D	2	/* read word in child's D space */
/* was	PT_READ_U	3	 * read word in child's user structure */
#define	PT_WRITE_I	4	/* write word in child's I space */
#define	PT_WRITE_D	5	/* write word in child's D space */
/* was	PT_WRITE_U	6	 * write word in child's user structure */
#define	PT_CONTINUE	7	/* continue the child */
#define	PT_KILL		8	/* kill the child process */
#define	PT_STEP		9	/* single step the child */
#define	PT_ATTACH	10	/* trace some running process */
#define	PT_DETACH	11	/* stop tracing a process */
#define PT_IO		12	/* do I/O to/from stopped process. */
#define	PT_LWPINFO	13	/* Info about the LWP that stopped. */
#define PT_GETNUMLWPS	14	/* get total number of threads */
#define PT_GETLWPLIST	15	/* get thread list */
#define PT_CLEARSTEP	16	/* turn off single step */
#define PT_SETSTEP	17	/* turn on single step */
#define PT_SUSPEND	18	/* suspend a thread */
#define PT_RESUME	19	/* resume a thread */
#define	PT_TO_SCE	20
#define	PT_TO_SCX	21
#define	PT_SYSCALL	22
#define	PT_FOLLOW_FORK	23
#define PT_GETREGS      33	/* get general-purpose registers */
#define PT_SETREGS      34	/* set general-purpose registers */
#define PT_GETFPREGS    35	/* get floating-point registers */
#define PT_SETFPREGS    36	/* set floating-point registers */
#define PT_GETDBREGS    37	/* get debugging registers */
#define PT_SETDBREGS    38	/* set debugging registers */
#define	PT_VM_TIMESTAMP	40	/* Get VM version (timestamp) */
#define	PT_VM_ENTRY     41 	/* Get VM map (entry) */

#define WNOHANG		1	/* dont hang in wait */
#define WUNTRACED	2	/* tell about stopped, untraced children */

struct ptrace_io_desc {
	int	piod_op;        /* I/O operation */
	void *piod_offs;	/* child offset */
	void *piod_addr;	/* parent offset */
	uint64_t piod_len;	/* request length */
};

// this structure is 100% wrong
struct ptrace_lwpinfo {
	uint32_t pl_lwpid;
	int pl_event;
	int pl_flags;
	uint32_t pl_sigmask;
	uint32_t pl_siglist;
	uint32_t pl_siginfo;
	char pl_tdname[32 + 1];
	uint32_t pl_child_pid;
	uint32_t pl_syscall_code;
	uint32_t pl_syscall_narg;
};

int ptrace(int req, int pid, void *addr, int data);
int wait4(int wpid, int *status, int options, void *rusage);

#endif
