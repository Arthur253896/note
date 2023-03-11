# Linux 命令大全

## 解压命令

### tar
解压： tar xvf FileName.tar
打包： tar cvf FName.tar DirName
(tar是打包不是压缩！)

### .gz
解压1： gunzip FN.gz
解压2: gzip -d FN.gz
压缩： gzip FN

### .tar.gz and .tgz
解压： tar zxvf FN.tar.gz
压缩： tar zcvf FN.tar.gz DirName

### .bz2
1： bzip -d FN.bz2
2: bunzip FN.bz2
压缩： bzip2 -z FN

### .tar.bz2

解压：tar jxvf FileName.tar.bz2
压缩：tar jcvf FileName.tar.bz2 DirName

### .bz

解压1：bzip2 -d FileName.bz
解压2：bunzip2 FileName.bz

### .tar.bz
解压：tar jxvf FileName.tar.bz

## deb 安装

### 使用dpkg
sudo dpkg -i ""

### apt

sudo apt install ""

## root 权限
sudo -i 临时权限
su 永久权限

## tail命令
    tail -x /location
显示文件的最后x行

## 编写Makefile文件
Makefile由一组规则组成：
    target...:prerequisites...
        command1
        command2
        ...
例如：
    main:main.o stack.o maze.o
        gcc main.o stack.o maze.o -o main
main是这条规则的目标，main.o、stack.o和maze.o是这条规则的条件标和条件之间的关系是：欲更新目标，必须首先更新它的所有条件；所有条件中只要有一个条件被更新了，目标也必须随之被更新。所谓“更新”就是执行一遍规则中的命令列表，命令列表中的每条命令必须以一个Tab开头，注意不能是空格，Makefile的格式不像C语言的缩进那么随意，对于Makefile中的每个以Tab开头的命令，make会创建一个Shell进程去执行它。

对于上面这个例子，make执行如下步骤：
1. Makefile        main

尝试更新中第一条规则的目标，第一条规则的目标称为缺省目标，只要缺省目标更新了就算完成任务了，其它工作都是为这个目的而做的。由于我们是第一次编译，main文件还没生成，显然需要更新，但规则说必须先更新了main.o、stack.o和maze.o这三个条件，然后才能更新main。

2. 所以make会进一步查找以这三个条件为目标的规则，这些目标文件也没有生成，也需要更新，所以执行相应的命令（gcc -c main.c、gcc -c stack.c和gcc -c maze.c）更新它们。
3. 最后执行gcc main.o stack.o maze.o -o main更新main。

### 如何简便的写makefile？
一个目标依赖的所有条件不一定非得写在一条规则中，也可以拆开写，例如：
    main.o: main.h stack.h maze.h
    main.o: main.c 
        gcc -c main.c
就相当于：
    main.o: main.c main.h stack.h maze.h
        gcc -c main.c

把冗长的makefile可以写成：
    main: main.o stack.o maze.o
        gcc main.o stack.o maze.o -o main
    main.o:main.h stack.h maze.h
    stack.o:stack.h main.h
    maze.o:maze.h main.h

    clean:-rm main *.o
    .PHONY:clean