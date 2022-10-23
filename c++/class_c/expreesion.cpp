#include <stdio.h>
#include <string.h>
typedef struct stack{
    int data[100];
    int top;
}SqStack;
void InitialStack(SqStack &S){
    S.top=-1;
}
bool StackEmpty(SqStack &S){
    if(S.top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(SqStack &S,int x){
    if(S.top==99){
        printf("³¬³ö·¶Î§£¡");//Õ»Âú
    }
    S.top++;
    S.data[S.top]=x;
}
int pop(SqStack &S){
    int x;
    if(S.top==-1){
        return -1;
    }
    else{
        x=S.data[S.top];
        S.top--;
        return x;
    }
}
int main(){
    char s[30]={8,1,2,'+',4,'*','+'};
    int i=0;
    stack s1;
    InitialStack(s1);
    int a,b,c;
    while(i<strlen(s)){
        if(s[i]=='*'){
            a=pop(s1);
            b=pop(s1);
            c=a*b;
            push(s1,c);
            i++;
        }
        if(s[i]=='+'){
            a=pop(s1);
            b=pop(s1);
            c=a+b;
            push(s1,c);
            i++;
        }
        if(s[i]=='-'){
            a=pop(s1);
            b=pop(s1);
            c=a-b;
            push(s1,c);
            i++;
        }
        if(s[i]=='/'){
            a=pop(s1);
            b=pop(s1);
            c=a/b;
            push(s1,c);
            i++;
        }
        else{
            push(s1,s[i]);
            i++;
        }
    }
    printf("%d",s1.data[0]);
    return 0;
}