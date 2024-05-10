#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int Mev(int q[],int n)
{
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[q[i]]++;

    for(int i=0;i<=n;i++)
	{
		if(mp[i] == 0) return i;
	}
}
void solve()
{
    int n;
    cin>>n;
    int q[n+1];
    for(int i=1;i<=n;i++) cin>>q[i];
    int mev=Mev(q,n);

    int st=1e9,ed=-1e9;
    for(int i=1;i<=n;i++)
    {
        if(q[i]==mev+1)
        {
            st=min(st,i);
            ed=max(ed,i);
        }
    }
    if(st==1e9){
        if(mev==n) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
        return ;
    }

    for(int i=st;i<=ed;i++) q[i]=mev;
    int now=Mev(q,n);
    if(now==mev+1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}