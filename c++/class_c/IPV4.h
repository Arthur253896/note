#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool IsIpv4(char *IPV4){
    int SepSize=atoi(IPV4);
    if(IPV4[0]=='0'){
        cout<<"不能0开头"<<endl;
        return false;
    }
    else if(IPV4[0]=='.'){
        cout<<"不能0开头"<<endl;
        return false;
    }
    else if(strlen(IPV4)>3){
        cout<<"超出位数！"<<endl;
        return false;
    }
    else if(strlen(IPV4)==0){
        cout<<"地址不能为0"<<endl;
        return false;
    }
    else if(SepSize>255){
        cout<<"地址长度过大！"<<endl;
        return false;
    }
    return true;

}