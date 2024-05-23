/*
    此题与一个题相似——两个有序数组的合并
    只不过这题改成了链表的形式

    复习一下：
    链表在代码的实现有很多种
    1.结构体+指针的组合
    2.数组模拟链表
    3.c++ stl库
*/
#include <cstdio>
#include <cmalloc>
#include <iostream>
using namespace std;

typedef struct array{
	int val;
	struct array *next;
} LinkList;
LinkList* createlist(int len)
{
    LinkList *head,*node,*end;
    head=(LinkList*) malloc(sizeof(LinkList));
    head->next=NULL;
    end=head;
    for(int i=1;i<=len;i++){
        node=(LinkList*) malloc(sizeof(LinkList));
        scanf("%d",&node->val);
        node->next=end;
        
    }
}
int main()
{
    //两个链表的大小
    int n,m;
    cin>>n>>m;
   LinkList L1,L2;
   L1=createlist(n);
   L2=createlist(m);
    return 0;
}