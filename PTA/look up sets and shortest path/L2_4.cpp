#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int p[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int find(int x)
{
    if(p[x]==x) return p[x];
    else {
        p[x]=find(p[x]);
        return p[x];//回溯
    }
}
void memge(int a,int b)
{
    p[find(a)]=find(b);
}
int main()
{
        cinquick();

        for(int i=1;i<=10010;i++) p[i]=i;
        int n;
        cin>>n;
        int s=0;
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            int st;
            cin>>st;
            s=max(s,st);
            for(int j=1;j<=k-1;j++)
            {
                int x;
                cin>>x;
                s=max(s,x);
                memge(st,x);
                st=x;
            }
        }

        for(int i=1;i<=10;i++)
        {
            cout<<find(i)<<' ';
        }
        // int cnt=0;
        // for(int i=1;i<=s;i++)
        // {
        //     if(p[i]==i) cnt++;
        // }
        // cout<<s<<' '<<cnt<<endl;
        // int q;
        // cin>>q;

        // while(q--)
        // {
        //     int a,b;
        //     cin>>a>>b;
        //     if(find(a)==find(b)) cout<<"Y"<<endl;
        //     else cout<<"N"<<endl;
        // }
        return 0;
}