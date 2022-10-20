#include <iostream>
#include <vector>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}LNode,*LinkList;
LinkList CreateLinkList(LinkList &L,vector<int> a){
    LinkList s;
    L=(node*)malloc(sizeof(node));
    L->next=NULL;
    for(int j=0;j<a.size();j++){
        for(int i=0;i<a.size();i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    }
    while(a.size()>0){
        int x=a[a.size()-1];
        s=(node*)malloc(sizeof(node));
        s->data=x;
        s->next=L->next;
        L->next=s;
        a.pop_back();
    }
    return L;
}
void PrintList(LinkList L)
{
	LinkList p;
	p = L->next;
	cout << "节点如下" << endl;
	while (p != NULL)
	{
		cout << p->data <<" ";
		p = p->next;
	}
	cout << endl;
}
LinkList Insert(LinkList&L,int x){
    LinkList s;
    LNode *p,*q;
    p=L->next;
    q=L;
    s=(node*)malloc(sizeof(node));
    while(p!=NULL){
        if(p->data<=x){
            p=p->next;
            q=q->next;
        }
        else{
            s->data=x;
            s->next=p->next;
            p->next=s;
            break;
        }
    }
    if(p==NULL){
        s->data=x;
        s->next=NULL;
        q->next=s;
    }
    return L;
}
LinkList Delete_num(LinkList &L,int x){
    LinkList p;
    LinkList q;
    p=L->next;
    q=L;
    while(p!=NULL){
        if(p->data==x){
          q->next=p->next;
          free(p);
          p=q->next;
    } 
    else{
        p=p->next;
        q=q->next;
    }
    }
    cout<<1<<endl;
    return L;
}
LinkList Delete_place(LinkList &L,int x){
    LinkList p;
    LinkList q;
    p=L->next;
    q=L;
    while(p!=NULL){
        for(int i=0;i<x;i++){
        p=p->next;
        q=q->next;
    }
        q->next=p->next;
        free(p);
        p=q->next;
    }
    return L;
}
void Search(LinkList &L,int x){
    LinkList p;
    p=L->next;
    int i=1;
    while(p!=NULL){
        while(p->data==x){
            cout<<x<<"的位置在第"<<i<<"个位置"<<endl;
            p=p->next;
            i++;
        }
        p=p->next;
        i++;
    }
}
int main(){
    vector<int> vec1;
    vec1={6,7,43,5,39,8,8,48,35,34};
    LinkList L1;
    L1=CreateLinkList(L1,vec1);
    PrintList(L1);
    Search(L1,8);
    Delete_num(L1,8);
    PrintList(L1);
    Delete_place(L1,7);
    PrintList(L1);
    Insert(L1,27);
    PrintList(L1);
    return 0;
}