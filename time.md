# ```time.h```

## 1. 函数名称: ```localtime```

函数原型: ```struct tm *localtime(const time_t *timer);```

函数功能: 返回一个以tm结构表达的机器时间信息

函数返回: 以tm结构表达的时间，结构tm定义如下:

``` C
#ifndef _TM_DEFINED
　　struct tm {
    　　int tm_sec;     /* 秒 – 取值区间为[0,59] */
    　　int tm_min;     /* 分 - 取值区间为[0,59] */
    　　int tm_hour;    /* 时 - 取值区间为[0,23] */
    　　int tm_mday;    /* 一个月中的日期 - 取值区间为[1,31] */
    　　int tm_mon;     /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
    　　int tm_year;    /* 年份，其值等于实际年份减去1900 */
    　　int tm_wday;    /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
    　　int tm_yday;    /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
    　　int tm_isdst;   /* 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
　　};
　　#define _TM_DEFINED
　　#endif
```

参数说明: ```timer```-使用```time()```函数获得的机器时间

所属文件: ```<time.h>```

``` C
#include<time.h>
#include<stdio.h>

int main() {
    time_t timer;
    struct tm *tblock;
    timer = time();                 // 这个函数是用来设置一个钟表
    tblock = localtime(&timer);     // 问问刚才的钟表现在的时间是多少
    printf("Local time is: %s", asctime(tblock));
    return 0;
}
```

## 2. 函数名称: ```asctime```

函数原型: ```char* asctime(struct tm * ptr);```


函数功能: 得到机器时间(日期时间转换为ASCII码)

函数返回: 返回的时间字符串格式为：星期,月,日,小时:分:秒,年

参数说明: 结构指针ptr应通过函数```localtime()```和```gmtime()```得到

## 3. 函数名称: ```ctime```

函数原型: ```char *ctime(const time_t *time);```

函数功能: 得到日历时间

函数返回: 返回字符串格式：星期,月,日,小时:分:秒,年

参数说明: time-该参数应由函数time获得

所属文件: ```<time.h>```

``` C
#include<stdio.h>
#include<time.h>

int main() {
    time_t t;
    time(&t);       // 这个time()函数还可以接受参数
                    // 把时间写到time_t变量里
    printf("Today's date and time: %s", ctime(&t));
    return 0;
}
```

## 4. 函数名称: ```difftime```

函数原型: ```double difftime(time_t time2, time_t time1)```

函数功能: 得到两次机器时间差，单位为秒

函数返回: 时间差，单位为秒

参数说明: ``time1``-机器时间1，``time2``-机器时间2，该参数应使用time函数获得

所属文件: <time.h>

``` C
// 以下代码尽在macOS下运行通过
// 其他操作系统未经过测试

#include <time.h>
#include <stdio.h>

int main() {
    time_t start, end;
    time(&start);
    delay(5000);    // 这个函数在C99下得不到支持
    time(&end);
    printf("The difference is: %f seconds", difftime(end, start));
    return 0;
}
```

## 5. 函数名称: gmtime

函数原型: ```struct tm *gmtime(time_t *time)```

函数功能: 得到以结构```tm```表示的时间信息

函数返回: 以结构```tm```表示的时间信息指针

参数说明: ```time```-用函数```time()```得到的时间信息

所属文件: ```<time.h>```

``` C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

char *tzstr = "TZ=PST8PDT";

int main() {
    time_t t;
    struct tm *gmt, *area;
    putenv(tzstr);
    tzset();
    t = time(NULL);
    area = localtime(&t);
    printf("Local time is: %s", asctime(area));
    gmt = gmtime(&t);
    printf("GMT is: %s", asctime(gmt));
    return 0;
}
```

## 6. 函数名称: time

函数原型: ```time_t time(time_t *timer)```

函数功能: 得到系统当前的日历时间

函数返回: 系统当前日历时间，如果不能获得当前日历时间，则返回-1

参数说明: ```timer=NULL```时得到机器日历时间，timer为有效指针时，更新timer为系统当前时间，```time_t```是一个```long```类型

所属文件: ```<time.h>```

``` C
#include<time.h>
#include<stdio.h>
#include<dos.h>
int main() {
    time_t t;
    t = time(NULL);     // 默认1970-1-1
    printf("The number of seconds since January1, 1970 is %ld", t);
    return 0;
}
```

## 7. 函数名称: tzset

函数原型: ```void tzset(void)```

函数功能: UNIX兼容函数，用于得到**时区**，在DOS环境下无用途
函数返回:
参数说明:
所属文件: ```<time.h>```

``` C
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
int main() {
    time_t td;
    putenv("TZ=PST8PDT");   // 这个环境变量不会被保留
    tzset();
    time(&td);
    printf("Current time = %s", asctime(localtime(&td)));
    return 0;
}
```
