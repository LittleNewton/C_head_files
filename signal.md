# ```signal.h```

C标准函数库中的信号处理部分.

定义了程序执行时如何处理不同的信号。

信号用作进程间通信，报告异常行为（如除零）、用户的一些按键组合（如同时按下Ctrl与C键，产生信号```SIGINT```）。

C++中的对应头文件是csignal。头文件```<signal.h>```中提供了一些用于处理程序运行期间所引发的异常条件的功能，如处理来源于外部的中断信号或程序执行期间出现的错误等事件。

## 1. signal

函数原型：```void (*signal(int sig, void (*handler)(int)))(int);```

函数返回值：该函数返回信号处理程序之前的值，当发生错误时返回 SIG_ERR。

signal()用于确定**以后**当信号sig出现时的处理方法。

- 如果```handler```的值是```SIG_DFL```，那么就采用实现定义的缺省行为；
- 如果```handler```的值是```SIG_IGN```，那么就忽略该信号；
- 否则，调用```handler```所指向的函数(参数为信号类型)。有效的信号包括：

|信号名|含义|
|:------|:-----|
|```SIGABRT``` | 异常终止，如调用```abort()```|
|```SIGFPE```  | 算术运算出错，如除数为```0```或溢出|
|```SIGILL```  | 非法函数映象，如非法指令。|
|```SIGINT```  | 交互式信号，如Ctrl + C中断|
|```SIGSEGV``` | 非法访问存储器，如访问不存在的内存单元|
|```SIGTERM``` | 发送给本程序的终止请求信号|

```signal()```返回信号```sig```原来的```handler```；如果出错，则返回```SIG_ERR```。

当随后出现信号```sig```时，就中断正在执行的操作，转而执行信号处理函数```(*handler)(sig)```。

如果从信号处理程序中返回，则从中断的位置继续执行。

信号的初始状态由实现定义。

## 2. raise

函数原型：```int raise(int sig);```

返回值：如果成功该函数返回0，否则返回非零。

C 库函数```int raise(int sig)```会促使生成信号```sig```。```sig```参数与 ```SIG```宏兼容。

``` C
#include <signal.h>
#include <stdio.h>

void signal_catchfunc(int);

int main() {
    int ret;
    ret = signal(SIGINT, signal_catchfunc);

    if( ret == SIG_ERR) {
        printf("错误：不能设置信号处理程序。\n");
        exit(0);
    }
    printf("开始生成一个信号\n");
    ret = raise(SIGINT);
    if(ret != 0) {
        printf("错误：不能生成 SIGINT 信号。\n");
        exit(0);
    }

    printf("退出...\n");
    return(0);
}

void signal_catchfunc(int signal) {
    printf("!! 信号捕获 !!\n");
}
```