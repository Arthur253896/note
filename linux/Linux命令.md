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