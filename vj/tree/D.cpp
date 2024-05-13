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
    char date;
    int l,r;
    node(char val='+'):date(val)
    {}
}tree[N];
string ans;
int n,idx;
void dfs(int root)
{
        if(tree[root].date=='+') return ;
        ans+=tree[root].date;
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
            if(i==1) root=(str[0]-'a');
            tree[str[0]-'a'].date=str[0];
            if(str[1]!='*')tree[str[0]-'a'].l=str[1]-'a';
            if(str[2]!='*')tree[str[0]-'a'].r=str[2]-'a';
        }
        dfs(root);
        cout<<ans<<endl;
        return 0;
}