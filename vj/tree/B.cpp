#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
struct  node
{
    int date;
    node *l;
    node *r;
     node(int val=0,node *lt=NULL,node *rt=NULL):date(val),l(lt),r(rt)
     {}
};
int n;
const int N=1e6+10;
pair<int,int> v[N];

void preorder(node* u)
{
    if(u){
        cout<<u->date<<' ';
        preorder(u->l);
        preorder(u->r);
    }
}
void inorder(node*u)
{
    if(u){
        inorder(u->l);
        cout<<u->date<<' ';
        inorder(u->r);
    }
}
void postorder(node *u)
{
    if(u){
        postorder(u->l);
        postorder(u->r);
        cout<<u->date<<' ';
    }
}
int main()
{
        cinquick();
        cin>>n;
        

        for(int i=1;i<=n;i++){
            cin>>v[i].first>>v[i].second;
        }

        node* tree[n+1];
        for(int i=1;i<=n;i++){
            tree[i]=new node;
            tree[i]->date=i;
        }
        for(int i=1;i<=n;i++){
           int lid=v[i].first,rid=v[i].second;
            if(lid) tree[i]->l=tree[lid];
     
            if(rid) tree[i]->r=tree[rid];
      
        }
        node *  T= tree[1];
        preorder(T);
	    cout <<endl;
	    inorder(T);
	    cout << endl;
	    postorder(T);
        return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// struct BNode{
// 	int data;
// 	 BNode* rchild;
// 	 BNode* lchild;
// };
// typedef BNode* BTree;
// void preorder(BTree T){	//二叉树的前序遍历 
// 	if(T){
// 		cout << T->data<<" ";
// 		preorder(T->lchild);
// 		preorder(T->rchild); 
// 	} 
// }

// void inorder(BTree T){	//二叉树的中序遍历 
// 	if(T){
// 		inorder(T->lchild);
// 		cout << T->data<<" ";
// 		inorder(T->rchild); 
// 	} 
// }

// void postorder(BTree T){	//二叉树的后序遍历 
// 	if(T){
// 		postorder(T->lchild);
// 		postorder(T->rchild); 
// 		cout << T->data<<" ";
// 	} 
// }
// int main()
// {	 
// 	int n;
// 	cin >> n;
// 	int a[n+1][2]={0};
	
// 	for(int i=1;i<=n;i++)
// 	{
// 		cin >> a[i][0]>>a[i][1];	
// 	} 
	
// 	BNode* tree[n+1];		//创建n+1个结构体指针(0不用，方便)
// 	 for(int i=1;i<=n;i++)
// 	 {
// 	 	tree[i] = new BNode;//创建结点实体 
// 	 	tree[i]->data = i;
// 	 }
	 
// 	 for(int i=1;i<=n;i++)
// 	 {
// 	 	if(a[i][0]!=0)
// 	 	tree[i]->lchild = tree[a[i][0]];
// 	 	else tree[i]->lchild = NULL;
// 	 	if(a[i][1]!=0)
// 	 	tree[i]->rchild = tree[a[i][1]];
// 	 	else tree[i]->rchild = NULL;
// 	 }
// 	BTree T = tree[1];	//指向根节点
	
// 	preorder(T);
// 	cout <<endl;
// 	inorder(T);
// 	cout << endl;
// 	postorder(T);
	
// 	return 0;
// }

