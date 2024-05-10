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
        vector<pair<int,int>> ans;
        if(n0==0||n1==0||n==0)
        {
            // if(n0==0&&n1!=0&&n1%n==0)
            //     ans.push_back({0,n});
            // if(n1==0&&n0!=0&&n0/n==0) ans.push_back({n,0});
            // if(n0==0&&n1==0&&n==0) ans.push_back({0,0});
            cout<<"No Solution"<<endl;
        }
        else
        {
            for(int x=1;x<n;x++)
            {
                int y=n-x;
                if(n0%x==0&&n1%y==0){
                ans.push_back({x,y});
                }
            }
        }


        int a=0,b=0,minv=0x3f3f3f3f;
        for(auto x:ans)
        {
            int v=x.first,nan=x.second;
            //cout<<v<<' '<<nan<<endl;
            int vm=0,nm=0;
            if(v)
             vm=n0/v;
            if(nan)
             nm=n1/nan;
            //cout<<vm<<' '<<nm<<endl;
            if(abs(vm-nm)<minv)
            {
                a=v,b=nan;
                minv=abs(vm-nm);
            }
        }
        if(minv==0x3f3f3f3f) cout<<"No Solution"<<endl;
        else cout<<a<<' '<<b<<endl;
        return 0;
}


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