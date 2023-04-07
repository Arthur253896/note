#include <stdio.h>
int a[5]={23,34,338,44,5};
//排序均用数组t[5,3,5,8,13]
//简化桶排序
int tong_sort_sim(){//0-1000，1001个桶  
    int book[1001],i,j,t;
    for(i=0;i<=1000;i++){
        book[i]=0;//初始化值
    }
    for(i=0;i<5;i++){//输入
        scanf("%d",&t);
        book[t]++;//计数
        }
    for(i=1000;i>=0;i--){
        for(j=1;j<=book[i];j++)
            printf("%d>",i);//如果出现次数多于1次则打印，出现几次打印几次
    }
    getchar();
    getchar();
    return 0;
}
//如果输入n个数则m+n+m+n次共O(M+N)
//冒泡排序
int pop_sort(){
    int a[100],i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){//从第一位开始比较直到最后一个尚未归位的数
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
//快排
void quicksort(int left,int right){
    int i,j,k,temp;
    if(left>right)
        return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j){
        //顺序很重要，要从右往左找
        while(a[j]>=temp && i<j) 
            j--;//右边大下一个
        while(a[i]<=temp && i<j) 
            i++;//左边小下一个
        if(i<j){
            k=a[i];
            a[i]=a[j];
            a[j]=k;
        }
    }
    //最终将基数归位
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1);//继续处理左边
    quicksort(i+1,right);//继续处理右边
}
//深度优先搜索
void dfs(int step)//step代表现在在哪个节点{
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