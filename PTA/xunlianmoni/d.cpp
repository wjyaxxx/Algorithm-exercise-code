#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int q[N];
stack<int> a;
vector<int> ans[N];
int n,m,k;

void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();

        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) cin>>q[i];

        int idx=1,chose=0;
       while(true)
        {
            if(ans[chose].size()==k) chose++;
            if(idx>n&&a.empty()) break;
            
            if(!a.empty()&&(ans[chose].empty()||a.top()<=ans[chose].back()))
            {
                ans[chose].push_back(a.top());
                a.pop();
            }
            else if(idx<=n&&(ans[chose].empty()||q[idx]<=ans[chose].back()))
            {
                ans[chose].push_back(q[idx++]);
            }
            else if(idx<=n&&a.size()<m)
            {
                a.push(q[idx++]);
            }
            else {
                chose++;
            }
            
        }


        for(int i=0;i<=chose;i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j];
			if(j!=ans[i].size()-1) cout<<" ";
			else cout<<endl;
		}
        }

        return 0;
}