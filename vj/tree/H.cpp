#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=1<<20;
int n;
int tree[N];
string str;
int build(int l,int r,string str,int u)
{
    
    if(str.size()==1){
        if(str[0]=='0') {
            tree[u]=0;
            return 0;
        }
        else {
            tree[u]=1;
            return 1;
        }
    }
    int n=str.size();
    tree[u*2]=build(l,l+n/2-1,str.substr(0,n/2),u*2);
    tree[u*2+1]=build(n/2,r,str.substr(n/2,n),u*2+1);
    //cout<<u<<' '<<tree[2*u]<<' '<<tree[2*u+1]<<endl;
    if(tree[u*2]==1&&tree[u*2+1]==1) return 1;
    else if(tree[u*2]==0&&tree[u*2+1]==0) return 0;
    else return 2;
    
}
string ans="BIF";
void dfs(int u)
{
    if(tree[u]==-1) return ;
    dfs(2*u);
    dfs(2*u+1);
    cout<<ans[tree[u]];
}
int main()
{
        cinquick();
        cin>>n;
        cin>>str;
        memset(tree,-1,sizeof tree);
        tree[1]=build(0,n-1,str,1);
        dfs(1);
        return 0;
}

                            
              