
#include<bits/stdc++.h>
using namespace std;
const int  maxn =1100;
typedef long long LL;
LL fact[maxn], infact[maxn];
int sk[maxn],tt;
int num[maxn];
int main()
{
    
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> ans[20];
    int p=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>num[i];
    }

    for(int i=1;i<=n;i++)
    {
        int x=num[i];
        if(!ans[p].empty()&&sk[tt]<=ans[p].back())
        {
            if(ans[p].size()==k) p++;
            ans[p].push_back(sk[tt--]);
        }
        else if(ans[p].empty()||(sk[tt]>ans[p].back()&&x<=ans[p].back())){
            if(ans[p].size()==k) p++;
            ans[p].push_back(x);
        }
        else
        {
            if(tt+1<=m) sk[++tt]=x;
            else{
                p++;
                i--;
            }
        }
    }
    while(tt)
    {
        if(ans[p].size()==k) p++;
        ans[p].push_back(sk[tt--]);
    }

    for(int i=0;i<=p;i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}