#include <iostream>
#include <cstring>
using namespace std;
bool IsIpv6(char *Ipv6){
    int i = 0;
	if (Ipv6[0] == ':'){
		cout<<"��ַ������ �� ��ͷ"<<endl;
		return false;
	}
	else if(strlen(Ipv6) > 4){
		cout<<"��ַ���ȹ���"<<endl;
		return false;
	}
	else if(strlen(Ipv6) == 0){
		cout<<"��ַ���Ȳ���Ϊ�գ�"<<endl;
		return false;
	}
	for (i = 0; i < strlen(Ipv6); i++)
	{
		if ((Ipv6[i] >= '0' && Ipv6[i] <= '9') || (Ipv6[i] >= 'a' && Ipv6[i] <= 'f') || (Ipv6[i] >= 'A' && Ipv6[i] <= 'F'))
			continue;
		else{
			cout<<"��ĸӦ��a-f֮�䣡"<<endl;
			return false;
		}
	}
	return true;
}