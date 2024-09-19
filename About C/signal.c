
/*

Exception 定義：
   A transform of control to kernel in response of some error event.

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Terminate flag
sig_atomic_t volatile finished = 0;

// Signal handler function
void divide_by_zero_handler(int signum) {
    switch (signum) {
    // hardware interrupts should not return
    case SIGFPE:
	    printf("Error: Division by zero!\n");
        
        // let everybody know that we are finished
        finished = signum;
        
        exit(EXIT_FAILURE);
	    //quick_exit(EXIT_FAILURE);
	    // 注意 quick_exit 在 C11 才出現，在 C99 可改寫為_exit(EXIT_FAILURE);

    default:
        /* Reset the signal to the default handler,
         * so we will not be called again if things go
         * wrong on return.
         */
        signal(signum, SIG_DFL);

        // let everybody know that we are finished
        finished = signum;
        return;
    }
}

int main() {

/*

# 1

在 Ｃ 常遇到的error是segment fault

# It occurs when a program instruction tries to access a memory address that is prohibited from getting accessed.

＃引起錯誤的可能總結起來有：
* Write or update read-only memory (const) / or something cannot be changed in kernel
* beyond array boundary
* dereference NULL
* Use pointer that reference to NULL

# 預防措施
* Initialize pointers before using
* Check pointers before using
* Check pointer before free
* Minimize creating pointers:

# 其他hint (https://opensourcedoc.com/applied-c-programming/error-handling/)
* exit() 函式和 abort() 函式的用途皆為提早結束程式。exit() 會完成清理的動作後再結束程式，而 abort() 則會立即結束程式。只是這樣無法細部處理例外，所以除了嚴重的錯誤外，不應隨意呼叫這兩個函式。
* 可用assert 巨集在開發過程中確認程式是否有誤。assert 巨集會直接中止程式，其用途是在開發時間幫程式設計者防呆。使用assert的缺點是，頻繁的調用會極大的影響程式的效能，增加額外的開銷。所以在調試結束後，可以通過在包含#include 的語句之前插入 #define NDEBUG 來區隔
* error handle常見用go to搭配使用
If (error)
    // do something
    go to NAME;
NAME:
    // free or release …

*/

    // Initialize pointers before using
    int * p = calloc(1, sizeof(int));
        // work with *p;

    // Check pointers before using
    if (p != NULL) {
        // work with *p;
    }

    // Check pointers before free
    if (p != NULL) {
        free(p);
    }
    // free() 釋放的是 pointer 指向位於 heap 的連續記憶體，而非 pointer 本身佔有的記憶體 (*ptr)

    // Minimize creating pointers:
    // (1)
    int x = 3; 
    //printf("%d", *(&x));
    // (2)
    //x = customFunction(&x); // int customFunction(int * x);

    // Check size of array
    int arr[] = {1, 2, 3, 4, 5};
    // sizeof(arr) will work in main function
    // but after passing array by pointer, sizeof(arr) will return the size of the pointer >> had better pass correct size of array when calling functions







    // # 2
    // 其餘還有各種程式例外
    // 以下示範使用Signal做 Error handling的處理

    // Register the signal handler for SIGFPE (division by zero)
    if (signal(SIGFPE, divide_by_zero_handler) == SIG_ERR) {
        perror("could not establish handler for SIGFPE");
        return EXIT_FAILURE;
    }
    // Can Ignore the signal by setting with SIG_IGN
    signal(SIGINT, SIG_IGN);

    // Perform the division
    int dividend = 50;
    int divisor = 0;
    int quotient;
    quotient = (dividend / divisor);
    printf("Quotient: %d\n", quotient);

    // Default exception finish 
    if (finished) {
        fprintf(stderr, "we have been terminated by signal %d\n",
                (int) finished);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS; // 0 success or 1
}

/*

訊號定義在 <signal.h>

有關完整的signal介紹，如下列 ...

比較常見的訊號有：
SIGINT跟SIGQUIT：停止訊號Ctrl+C
SIGFPE：運算例外
SIGKILL：停止訊號
SIGSEGV：記憶體例外,又稱segment error

所有訊號列表：
SIGHUP (1):
* Signal sent to a process when its controlling terminal is closed or the process controlling it terminates.
SIGINT (2):
* Signal sent to a process by its controlling terminal when a user interrupts the process (usually by pressing Ctrl+C).
SIGQUIT (3):
* Signal sent to a process by its controlling terminal when a user requests to quit the process (usually by pressing Ctrl+).
SIGILL (4):
* Signal sent to a process when it attempts to execute an illegal, malformed, or privileged instruction.
SIGTRAP (5):
* Signal sent to a process when an exception is triggered (used by debuggers).
SIGABRT (6):
* Signal sent to a process to abort the process (e.g., by calling abort() function).
SIGBUS (7):
* Signal sent to a process when an attempt is made to access memory that the CPU cannot physically address.
SIGFPE (8):
* Signal sent to a process when it performs an arithmetic error, such as division by zero or an overflow.
SIGKILL (9):
* Signal sent to a process to immediately terminate it. This signal cannot be caught, blocked, or ignored.
SIGUSR1 (10):
* User-defined signal 1. It can be used for custom purposes defined by the user.
SIGSEGV (11):
* Signal sent to a process when it attempts to access memory it doesn't have permission to access, or when accessing memory outside of its address space.
SIGUSR2 (12):
* User-defined signal 2. Similar to SIGUSR1, it can be used for custom purposes defined by the user.
SIGPIPE (13):
* Signal sent to a process when it writes to a pipe or socket that has been closed by the other end.
SIGALRM (14):
* Signal sent to a process when a timer set by the alarm() function expires.
SIGTERM (15):
* Signal sent to a process to request its termination. Unlike SIGKILL, this signal can be caught, blocked, or ignored.
SIGSTKFLT (16):
* Signal sent to a process when it experiences a stack fault.
SIGCHLD (17):
* Signal sent to a parent process when a child process terminates or is stopped.
SIGCONT (18):
* Signal sent to a process to instruct it to continue if it was previously stopped (e.g., by SIGSTOP or SIGTSTP).
SIGSTOP (19):
* Signal sent to a process to instruct it to stop its execution. Unlike SIGKILL, this signal can be caught, blocked, or ignored.
SIGTSTP (20):
* Signal sent to a process by its controlling terminal to suspend its execution (usually by pressing Ctrl+Z).
SIGTTIN (21):
* Signal sent to a background process when it attempts to read input from its controlling terminal.
SIGTTOU (22):
* Signal sent to a background process when it attempts to write output to its controlling terminal.
SIGURG (23):
* Signal sent to a process to notify it of out-of-band data on a socket.
SIGXCPU (24):
* Signal sent to a process when it exceeds its CPU time limit.
SIGXFSZ (25):
* Signal sent to a process when it exceeds its file size limit.
SIGVTALRM (26):
* Signal sent to a process when a timer set by the setitimer() function expires.
SIGPROF (27):
* Signal sent to a process when a timer set by the setitimer() function for profiling expires.
SIGWINCH (28):
* Signal sent to a process when its controlling terminal is resized.
SIGIO (29):
* Signal sent to a process when input or output becomes available on a descriptor that is being monitored for asynchronous I/O.
SIGPWR (30):
* Signal sent to a process when a power failure is detected.
SIGSYS (31):
* Signal sent to a process when it attempts to use an invalid system call.
SIGTHR (32):
* Signal sent to a process when a thread-specific event occurs.
SIGLIBRT (33):
* Signal sent to a process when a real-time library routine reports an error.
SIGLWP (34):
* Signal sent to a process when a light-weight process (LWP) event occurs.
SIGCANCEL (35):
* Signal sent to a process when a cancellation request is made to a thread.
SIGRTMIN (36):
* The minimum real-time signal number.
SIGRTMIN (37):
* The maximum real-time signal number.
SIGRTMAX (38):
* The minimum real-time signal number.
SIGRTMAX (39):
* The maximum real-time signal number.

其他常數：
SIG_IGN:
* When a signal is set to SIG_IGN, it means that if that signal is received by the process, the default action associated with that signal (such as terminating the process) will be ignored.
SIG_ERR:
* It is typically used to indicate an error condition or an invalid signal handler function pointer returned by signal() or sigaction() functions when an error occurs.
* For example, if signal() fails to set a signal handler, it returns SIG_ERR.
SIG_DFL:
* It represents the default action for a signal.
* When a signal is received, the operating system performs the default action associated with that signal.
* For example, for signals like SIGINT, SIGQUIT, and SIGTERM, the default action is to terminate the process.
* You can set a signal handler to SIG_DFL if you want to restore the default behavior of a signal.

Signal知識參考來源：
https://hackmd.io/@sysprog/c-stream-io#signal

*/

