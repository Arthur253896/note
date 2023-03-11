# Linux �����ȫ

## ��ѹ����

### tar
��ѹ�� tar xvf FileName.tar
����� tar cvf FName.tar DirName
(tar�Ǵ������ѹ����)

### .gz
��ѹ1�� gunzip FN.gz
��ѹ2: gzip -d FN.gz
ѹ���� gzip FN

### .tar.gz and .tgz
��ѹ�� tar zxvf FN.tar.gz
ѹ���� tar zcvf FN.tar.gz DirName

### .bz2
1�� bzip -d FN.bz2
2: bunzip FN.bz2
ѹ���� bzip2 -z FN

### .tar.bz2

��ѹ��tar jxvf FileName.tar.bz2
ѹ����tar jcvf FileName.tar.bz2 DirName

### .bz

��ѹ1��bzip2 -d FileName.bz
��ѹ2��bunzip2 FileName.bz

### .tar.bz
��ѹ��tar jxvf FileName.tar.bz

## deb ��װ

### ʹ��dpkg
sudo dpkg -i ""

### apt

sudo apt install ""

## root Ȩ��
sudo -i ��ʱȨ��
su ����Ȩ��

## tail����
    tail -x /location
��ʾ�ļ������x��

## ��дMakefile�ļ�
Makefile��һ�������ɣ�
    target...:prerequisites...
        command1
        command2
        ...
���磺
    main:main.o stack.o maze.o
        gcc main.o stack.o maze.o -o main
main�����������Ŀ�꣬main.o��stack.o��maze.o����������������������֮��Ĺ�ϵ�ǣ�������Ŀ�꣬�������ȸ���������������������������ֻҪ��һ�������������ˣ�Ŀ��Ҳ������֮�����¡���ν�����¡�����ִ��һ������е������б������б��е�ÿ�����������һ��Tab��ͷ��ע�ⲻ���ǿո�Makefile�ĸ�ʽ����C���Ե�������ô���⣬����Makefile�е�ÿ����Tab��ͷ�����make�ᴴ��һ��Shell����ȥִ������

��������������ӣ�makeִ�����²��裺
1. Makefile        main

���Ը����е�һ�������Ŀ�꣬��һ�������Ŀ���ΪȱʡĿ�ֻ꣬ҪȱʡĿ������˾�����������ˣ�������������Ϊ���Ŀ�Ķ����ġ����������ǵ�һ�α��룬main�ļ���û���ɣ���Ȼ��Ҫ���£�������˵�����ȸ�����main.o��stack.o��maze.o������������Ȼ����ܸ���main��

2. ����make���һ������������������ΪĿ��Ĺ�����ЩĿ���ļ�Ҳû�����ɣ�Ҳ��Ҫ���£�����ִ����Ӧ�����gcc -c main.c��gcc -c stack.c��gcc -c maze.c���������ǡ�
3. ���ִ��gcc main.o stack.o maze.o -o main����main��

### ��μ���дmakefile��
һ��Ŀ������������������һ���ǵ�д��һ�������У�Ҳ���Բ�д�����磺
    main.o: main.h stack.h maze.h
    main.o: main.c 
        gcc -c main.c
���൱�ڣ�
    main.o: main.c main.h stack.h maze.h
        gcc -c main.c

���߳���makefile����д�ɣ�
    main: main.o stack.o maze.o
        gcc main.o stack.o maze.o -o main
    main.o:main.h stack.h maze.h
    stack.o:stack.h main.h
    maze.o:maze.h main.h

    clean:-rm main *.o
    .PHONY:clean