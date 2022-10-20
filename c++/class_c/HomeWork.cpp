#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "IPV4.h"
#include "IPV6.h"
using namespace std;
class Solution{
    public:
      int Rabbit_Both(int n1,int months);
      int BigNum(int n);
      int YTriangle(int m);
      int Ddz();
      void Ip(const char *ip);
};
int Solution::Rabbit_Both(int n1,int months){
    int n2=0;
    for(int i=1;i<=months;i++){
        n1=n1+n2;
        n2=n2+n1;
        cout<<"��"<<i<<"�������ӵ�����"<<n1<<endl;
    }
    return 0;
};
int Solution::BigNum(int n){
    int v[10000]={1};
    int index=0;
    for(int number=1;number<=n;number++){
        for(int i=number;i<=number;){
            int c=0;
            for(int j=0;j<=index;j++){
                v[j]*=i;
                if(c!=0){
                    v[j]+=c;
                    c=0;
                }
                if(v[j]>=10){
                    if(j==index){
                        index++;
                    }
                    c=v[j]/10;
                    v[j]%=10;
                }
            }
            i++;
        }
        //printf("%2d!=",number);
        cout<<number<<"!=";
        for(int m=index;m>=0;m--){
            cout<<v[m];
        }
        cout<<endl;
    }
    return 0;
}
int Solution::YTriangle(int n){
    vector<vector<int>> a;
    vector<int> b;
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			if (j == 1 || j == i){
                b.push_back(1);
                a.push_back(b);
            }
			else{
                b.push_back(1);
                a.push_back(b);
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
		}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
int Solution::Ddz(){
    int total[54];
    int player[3][17];
    int left=54;
    int ranNumber;
    unsigned seed;
    seed=time(0);
    srand(seed);
    for(int i=0;i<54;i++){
        total[i]=i+1; 
    }
    for(int i=0;i<17;i++){
        for(int j=0;j<3;j++){
            ranNumber=rand()%left;
            player[j][i]=total[ranNumber];
            total[ranNumber]=total[left-1];
            left--;      
        }
    }
    for(int i=0;i<3;i++){
        if(i==0){
                cout<<"a������:"<<endl;
            }
        cout<<endl;
        if(i==1){
                cout<<"b������:"<<endl;
            }
        cout<<endl;
        if(i==2){
                cout<<"c������:"<<endl;
            }
        for(int j=0;j<17;j++){
            if(player[i][j]<=10){
                cout<<"����"<<" "<<player[i][j]<<" ";
            }
            if(player[i][j]==11){
                cout<<"���� J"<<" ";
            }
            if(player[i][j]==12){
                cout<<"���� Q"<<" ";
            }
            if(player[i][j]==13){
                cout<<"���� K"<<" ";
            }
            if(player[i][j]>13&&player[i][j]<24){
                cout<<"����"<<" "<<player[i][j]-13<<" ";
            }
            if(player[i][j]==24){
                cout<<"���� J"<<" ";
            }
            if(player[i][j]==25){
                cout<<"���� Q"<<" ";
            }
            if(player[i][j]==26){
                cout<<"���� K"<<" ";
            }
            if(player[i][j]>26&&player[i][j]<36){
                cout<<"÷��"<<" "<<player[i][j]-26<<" ";
            }
            if(player[i][j]==37){
                cout<<"÷�� J"<<" ";
            }
            if(player[i][j]==38){
                cout<<"÷�� Q"<<" ";
            }
            if(player[i][j]==39){
                cout<<"÷�� K"<<" ";
            }
            if(player[i][j]>39&&player[i][j]<49){
                cout<<"����"<<" "<<player[i][j]-39<<" ";
            }
            if(player[i][j]==50){
                cout<<"���� J"<<" ";
            }
            if(player[i][j]==51){
                cout<<"���� Q"<<" ";
            }
            if(player[i][j]==52){
                cout<<"���� K"<<" ";
            }
            if(player[i][j]==53){
                cout<<"С��"<<" ";
            }
            if(player[i][j]==54){
                cout<<"����"<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<3;i++){
        if(total[i]<=10){
                cout<<"����"<<" "<<total[i];
            }
            if(total[i]==11){
                cout<<"���� J";
            }
            if(total[i]==12){
                cout<<"���� Q";
            }
            if(total[i]==13){
                cout<<"���� K";
            }
            if(total[i]>13&&total[i]<24){
                cout<<"����"<<" "<<total[i]-13;
            }
            if(total[i]==24){
                cout<<"���� J";
            }
            if(total[i]==25){
                cout<<"���� Q";
            }
            if(total[i]==26){
                cout<<"���� K";
            }
            if(total[i]>26&&total[i]<36){
                cout<<"÷��"<<" "<<total[i]-26;
            }
            if(total[i]==37){
                cout<<"÷�� J";
            }
            if(total[i]==38){
                cout<<"÷�� Q";
            }
            if(total[i]==39){
                cout<<"÷�� K";
            }
            if(total[i]>39&&total[i]<49){
                cout<<"����"<<" "<<total[i]-39;
            }
            if(total[i]==50){
                cout<<"���� J";
            }
            if(total[i]==51){
                cout<<"���� Q";
            }
            if(total[i]==52){
                cout<<"���� K";
            }
            if(total[i]==53){
                cout<<"С��";
            }
            if(total[i]==54){
                cout<<"����";
            }
    }
    cout<<endl;
    return 0;
}
void Solution::Ip(const char *IP){
	const char *cur, *pre;
	char ip[10] = { 0 };
	char len = 0;
	if (strchr(IP, '.'))
	{
		pre = IP;
		cur = strchr(IP, '.');    //�ҵ�'.'��λ��
		while (cur)
		{
			memcpy(ip, pre, cur - pre);    //ȡ������'.'֮����ַ�
			if (IsIpv4(ip) == false){
                cout<< "�Ⲣ����IPV4"<<endl;
                return;
            }
			pre = cur + 1;
			cur = strchr(pre, '.');
			memset(ip, 0, 10);
			len++;
			if (len > 3){
                cout<< "�Ⲣ����IPV4"<<endl;
                return;
            }        //�жϷ����Ƿ����ipv4Ҫ��
		}
		if (len != 3){
            cout<< "�Ⲣ����IPV4"<<endl;
            return;
        }
		memcpy(ip, pre, strlen(pre));
		if (IsIpv4(ip) == false){
            cout<< "�Ⲣ����IPV4"<<endl;;
            return;
        }
		cout<< "IPV4"<<endl;
	}
	else if (strchr(IP, ':'))
	{
		pre = IP;
		cur = strchr(IP, ':');
		while (cur)
		{
			memcpy(ip, pre, cur - pre);
			if (IsIpv6(ip) == false){
                cout<< "�Ⲣ����IPV6"<<endl;
                return;
            }
			pre = cur + 1;
			cur = strchr(pre, ':');
			memset(ip, 0, 10);
			len++;
			if (len > 7){
                cout<< "�Ⲣ����IPV6"<<endl;
                return;
            }
		}
		if (len != 7){
            cout<< "�Ⲣ����IPV6"<<endl;
                return;
        }
		memcpy(ip, pre, strlen(pre));
		if (IsIpv6(ip) == false){
            cout<< "�Ⲣ����IPV6"<<endl;
                return;
        }
		cout<< "IPV6"<<endl;
	}
    else{
        cout<< "�Ⲣ����IPV4"<<endl;
        cout<<"�Ⲣ����IPV6"<<endl;
    }
}
int main(){
    Solution slo;
    //slo.Rabbit_Both(1,12);
    slo.BigNum(40);
    //slo.YTriangle(80);
    /*for(int i=0;i<5;i++){
        slo.Ddz();
    }*/
    // const char *ip1="125.124.133.234";
    // slo.Ip(ip1);
    // const char *ip2="256.256.123.111";
    // slo.Ip(ip2);
    // const char *ip3="0.0.1.2";
    // slo.Ip(ip3);
    // const char *ip4="..1.1";
    // slo.Ip(ip4);
    // const char *ip5="2001:0db8:85a3:0:0:8A000E:0370:11";
    // slo.Ip(ip5);
    // const char *ip6="2001:0dz8:85a3:0:0:8A000E:0370:11";
    // slo.Ip(ip6);
    // const char *ip7="::1:1";
    // slo.Ip(ip7);
    // const char *ip8="1";
    // slo.Ip(ip8);
    // return 0;
};

