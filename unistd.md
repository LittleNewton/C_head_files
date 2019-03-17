# unistd.h中蕴含的函数

unistd.h 是 C 和 C++ 程序设计语言中提供对POSIX操作系统API的访问功能的标头档的名称。是Unix Standard的缩写。该头文件由 POSIX.1 标准（单一UNIX规范的基础）提出，故所有遵循该标准的操作系统和编译器均应提供该头文件（如 Unix 的所有官方版本，包括 Mac OS X、Linux 等）。

对于类 Unix 系统，unistd.h 中所定义的接口通常都是大量针对系统调用的封装（英语：wrapper functions），如 fork、pipe 以及各种 I/O 原语（read、write、close 等等）。

类似于 Cygwin 和 MinGW 的 Unix 兼容层也提供相应版本的 unistd.h。