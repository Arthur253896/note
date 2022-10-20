#include <iostream>
#include <vector>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
    struct node *prior;
}LNode,*LinkList;
LinkList CreateLinkList(LinkList &L,vector<int> a){
    LinkList s;
    L=(node*)malloc(sizeof(node));
    L->next=NULL;
    L->prior=NULL;
    LNode *q=L;
    for(int j=0;j<a.size();j++){
        for(int i=0;i<a.size();i++){
        if(a[i]<a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    }
    while(a.size()>0){
        int x=a[a.size()-1];
        s=(node*)malloc(sizeof(node));
        s->data=x;
        s->next=NULL;
        q->next=s;
        s->prior=q;
        q=q->next;
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
    LNode *p;
    p=L->next;
    s=(node*)malloc(sizeof(node));
    while(p!=NULL){
        if(p->data<=x){
            p=p->next;
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
        p->prior->next=s;
        s->prior=p->prior;
    }
    return L;
}
LinkList Delete_num(LinkList &L,int x){
    LinkList p;
    LinkList q;
    p=L->next;
    p->prior=L;
    q=L;
    while(p!=NULL){
        if(p->data==x){
            p->next->prior = p->prior;
            p->prior->next = p->next;
            p->next = p->prior = p;
            free(p);
            p=p->next;
            break;
        } 
        else{
            p=p->next;        
            q=q->next;
            p->prior=q;                        
        }
    }
    return L;
}
LinkList Search(LinkList &L,int x){
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
    return L;
}
int main(){
    vector<int> vec1;
    vec1={6,7,43,5,39,8,8,49,35,34};
    LinkList L1;
    L1=CreateLinkList(L1,vec1);
    PrintList(L1);
    Insert(L1,27);
    PrintList(L1);
    Delete_num(L1,27);
    PrintList(L1);
    Search(L1,8);
    return 0;
}