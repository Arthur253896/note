#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool IsIpv4(char *IPV4){
    int SepSize=atoi(IPV4);
    if(IPV4[0]=='0'){
        cout<<"����0��ͷ"<<endl;
        return false;
    }
    else if(IPV4[0]=='.'){
        cout<<"����0��ͷ"<<endl;
        return false;
    }
    else if(strlen(IPV4)>3){
        cout<<"����λ����"<<endl;
        return false;
    }
    else if(strlen(IPV4)==0){
        cout<<"��ַ����Ϊ0"<<endl;
        return false;
    }
    else if(SepSize>255){
        cout<<"��ַ���ȹ���"<<endl;
        return false;
    }
    return true;

}