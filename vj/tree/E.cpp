#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
const int N=110;
struct node
{
    int l,r; 
}tree[N];
string ans;
int n,idx;
void dfs(int root)
{
        if(!root) return ;
        ans+=(root-1+'a');
        dfs(tree[root].l); 
        dfs(tree[root].r); 
}
int main()
{
        cinquick();
        cin>>n;
        int root;
        string str;
        for(int i=1;i<=n;i++)
        {
            cin>>str;
            if(i==1) root=(str[0]-'a'+1);
            if(str[1]!='*') {
                tree[str[0]-'a'+1].l=(str[1]-'a'+1);
                
            }
            if(str[2]!='*') {
                tree[str[0]-'a'+1].r=(str[2]-'a'+1);
            }
        }
        
        dfs(root);
        cout<<ans<<endl;
        return 0;
}