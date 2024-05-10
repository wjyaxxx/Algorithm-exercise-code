#include <bits/stdc++.h>
using namespace std;
int q[10010][110];
struct node
{
    vector<int> num;
    int cnt;
}a[10010];
int n,m,idx;
map<vector<int>,int> mp;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}

bool cmp(node a,node b)
{
    if(a.cnt!=b.cnt) return a.cnt>b.cnt;
    
    for(int i=0;i<a.num.size();i++)
        if(a.num[i]!=b.num[i])
            return a.num[i]<b.num[i];
}
int main()
{
        cinquick();
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            vector<int> a(m);
            for(int j=0;j<m;j++) cin>>a[j];
            mp[a]++;
        }

        for(auto x:mp)
        {
            a[idx].num=x.first;
            a[idx].cnt=x.second;
            
            idx++;
        }
        sort(a,a+idx,cmp);
        cout<<idx<<endl;
        for(int i=0;i<idx;i++)
        {
            cout<<a[i].cnt<<' ';
            for(int j=0;j<a[i].num.size();j++)
                if(j==0) cout<<a[i].num[j];
                else cout<<' '<<a[i].num[j];
                cout<<endl;
        }
        return 0;
}