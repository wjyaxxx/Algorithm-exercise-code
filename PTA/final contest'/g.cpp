#include <bits/stdc++.h>
using namespace std;

int n0,n1,n;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        
        cin>>n0>>n1>>n;
        vector<int> pa;
        for(int i=2;i*i<=n0;i++)
            if(n0%i==0)
            {
                pa.push_back(i);
                pa.push_back(n0/i);
            }
        //n0的教室数
        vector<pair<int,int>> ans;
        for(auto x:pa)
        {
            int b=n-x;
            if(n1%b==0&&b>0) ans.push_back({x,b});
        }
        if(ans.empty()) {
            cout<<"No Solution"<<endl;
            return 0;
        }
        int minv=0x3f3f3f3f;
        for(auto x:ans)
        {
            int a=x.first,b=x.second;
            int v=n0/a-n1/b;
            minv=min(abs(v),minv);
        }
        int ansa=0,ansb=0;
        for(auto x:ans)
        {
            int a=x.first,b=x.second;
            
            int v=abs(n0/a-n1/b);
            if(v==minv) {
                cout<<a<<' '<<b<<endl;
                break;
            }
        }
        return 0;
}