#include <stdio.h>
int a[5]={23,34,338,44,5};
//�����������t[5,3,5,8,13]
//��Ͱ����
int tong_sort_sim(){//0-1000��1001��Ͱ  
    int book[1001],i,j,t;
    for(i=0;i<=1000;i++){
        book[i]=0;//��ʼ��ֵ
    }
    for(i=0;i<5;i++){//����
        scanf("%d",&t);
        book[t]++;//����
        }
    for(i=1000;i>=0;i--){
        for(j=1;j<=book[i];j++)
            printf("%d>",i);//������ִ�������1�����ӡ�����ּ��δ�ӡ����
    }
    getchar();
    getchar();
    return 0;
}
//�������n������m+n+m+n�ι�O(M+N)
//ð������
int pop_sort(){
    int a[100],i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){//�ӵ�һλ��ʼ�Ƚ�ֱ�����һ����δ��λ����
            if(a[j]>a[j+1]){
                int m=a[j];
                a[j]=a[j+1];
                a[j+1]=m;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void temp(int a,int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
//O(N^2)
//����
void quicksort(int left,int right){
    int i,j,k,temp;
    if(left>right)
        return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j){
        //˳�����Ҫ��Ҫ����������
        while(a[j]>=temp && i<j) 
            j--;//�ұߴ���һ��
        while(a[i]<=temp && i<j) 
            i++;//���С��һ��
        if(i<j){
            k=a[i];
            a[i]=a[j];
            a[j]=k;
        }
    }
    //���ս�������λ
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);//�����������
    quicksort(i+1,right);//���������ұ�
}
//�����������
void dfs(int step)//step�����������ĸ��ڵ�{
    int i;
    if(step==n+1)
}
int main(){
    // tong_sort_sim();
    // pop_sort();
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    quicksort(0,4);
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}