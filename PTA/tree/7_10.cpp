#include <bits/stdc++.h>
using namespace std;
const int N=11000;
int tree[N],tree1[N];
int a[N],b[N];
int n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int built(int al,int ar,int bl,int br,int h)
{
    if(al > ar || bl > br) return 0;
    int root=a[al];

    int k=1;
    while(b[k]!=root) k++;
    int len=k-bl;//左子树的长度

    tree[2*h]=built(al+1,al+len,bl,bl+len-1,2*h);
    tree[(2*h)+1]=built(al+len+1,ar,bl+len+1,br,h*2+1);
    return root;
}
void dfs(int u)
{
    if(tree[u]==0) return;
    
}
int main()
{
        cinquick();
        cin>>n;
        
        for(int i=1;i<=n;i++) cin>>b[i];//中序
        for(int i=1;i<=n;i++) cin>>a[i];//前序
       tree[1]=built(1,n,1,n,1);
        int cnt=0;
       
       dfs(1);
        for(int i=1;i<=N;i++){
            if(tree1[i])
                cout<<tree1[i]<<' ';
        }
        return 0;
}