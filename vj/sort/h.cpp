#include <bits/stdc++.h>

#define int long long
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int n;
const int N=10010;
int ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
signed main()
{
        cinquick();
        cin>>n;
        int x;
        for(int i=1;i<=n;i++){
            cin>>x;
            q.push(x);
        }
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            ans+=(a+b);
            q.push(a+b);
            
        }
        cout<<ans<<endl;
        return 0;
}