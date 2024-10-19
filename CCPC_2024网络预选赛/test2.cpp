#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
struct node
{
    int v;
    node*next;
    node(int x):v(x),next(NULL){};
};
//将h1和h2合并到h3链表
void Union1(node* LA, node* LB, node*& LC) {
    //建立两个辅助链表
    node* tempA = LA;
    node* tempB = LB;
    node* tail = NULL;
    //将A的元素拷贝到C
    while (tempA!= NULL) {
        node* newNode = new node(tempA->v);
        if (LC == NULL) {
            LC = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        tempA = tempA->next;
    }
    //在B中一个一个比对，若不同直接拷贝
    while (tempB!= NULL) {
        bool found = false;
        node* tempC = LC;
        while (tempC!= NULL) {
            if (tempC->v == tempB->v) {
                found = true;
                break;
            }
            tempC = tempC->next;
        }
        if (!found) {
            node* newNode = new node(tempB->v);
            if (LC == NULL) {
                LC = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        tempB = tempB->next;
    }
}

//集合交集
void Intersection(node* LA, node* LB, node*& LC) {
    //建立两个辅助链表
    
    node* tempB = LB;
    node* tail = NULL;

    while(tempB!=NULL){
        int ok=0;
        node* tempA = LA;
        while(tempA!=NULL){
            if(tempA->v==tempB->v){
                ok=tempA->v;
                break;
            }
            tempA=tempA->next;
        }
        if (ok) {
            node* newNode = new node(ok);
            if (LC == NULL) {
                LC = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        tempB=tempB->next;
    }
}
void print(node * & list1){
    node * temp=list1;
    while(temp!=NULL){
        cout<<temp->v<<' ';
        temp=temp->next;
    }
    cout<<"\n";
}
int main()
{
    read_fast
    node*head1=NULL;
    node * head2=NULL;
    node * t1=NULL;
    node * t2= NULL;
    int n;
    while(cin>>n && n!=-1){
        node* newnode =new node(n);
        if(head1==NULL){
            head1=newnode;
            t1=newnode;
        }else{
            t1->next=newnode;
            t1=newnode;
        }
    }

    while(cin>>n && n!=-1){
        node* newnode =new node(n);
        if(head2==NULL){
            head2=newnode;
            t2=newnode;
        }else{
            t2->next=newnode;
            t2=newnode;
        }
    }
    node* head3=NULL;
    Union1(head1,head2,head3);
    node *tmp=head3;
    print(tmp);
    node* head4=NULL;
    Intersection(head1,head2,head4);
    tmp=head4;
    print(tmp); 
    return 0;
}


