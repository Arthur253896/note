#include <stdio.h>

int main(){
    int n,a[1001],t;
    printf("�ж���ͬѧ����\n");
    scanf("%d",&n);
    printf("ISBN��\n");
    for(int i=0;i<1001;i++){
        a[i]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        a[t]=1;
    }
    int j=0;
    for(int i=0;i<1001;i++){
        if(a[i]==1){
            j++;
            printf("%d,",i);
        }
    }
    printf("\n");
    printf("%d",j);
    return 0;
}