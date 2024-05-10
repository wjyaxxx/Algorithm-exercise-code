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
        // while(true){
		// if(ans[chose].size()==k) chose++;
		// if(idx>n&&a.empty()) break;
		// if(!a.empty()&&(ans[chose].empty()||a.top()<=ans[chose].back())){
		// 	ans[chose].push_back(a.top());
		// 	a.pop();
		// }else if(idx<=n&&(ans[chose].empty()||q[idx]<=ans[chose].back())){
		// 	ans[chose].push_back(q[idx++]);
		// }else if(idx<=n&&a.size()<m){
		// 	a.push(q[idx++]);
		// }else {
		// 	chose++;
	    // }
        // }


        while(true)
        {
            if(ans[chose].size()==k) chose++;
            if(idx>n&&a.empty()) break;
            
            if(!a.empty()&&(ans[chose].empty()||a.top()<=ans[chose].back()))//取盒子中的
            {
                ans[chose].push_back(a.top());
                a.pop();
            }
            else if(idx<=n&&(q[idx]<=ans[chose].back()||ans[chose].empty()))//取推送器的
            {
                ans[chose].push_back(q[idx++]);
            }
            else if(idx<=n&&a.size()<m)//栈为空，将推送器中的压入栈中，和第一步操作合并,或者
            {
                a.push(q[idx++]);
            }
            else {
                chose++;
            }
            
        }

        for(int i=0;i<=chose;i++)
        {
            for(int j=0;j<ans[i].size();j++)
            if(j!=ans[i].size()-1)
                cout<<ans[i][j]<<' ';
            else cout<<ans[i][j];
            cout<<endl;
        }
        return 0;
}