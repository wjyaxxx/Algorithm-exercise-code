#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int e[N],ne[N];//原链表
int a[N];
int b[N];
bool h[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        int st,n;
        cin>>st>>n;
        for(int i=1;i<=n;i++)
        {
            int ad,v,nad;
            cin>>ad>>v>>nad;
            e[ad]=v;
            ne[ad]=nad;
        }
        int k=0,cnt=0;
        for(int i=st;i!=-1;i=ne[i])
        {
            int v=e[i];
            int v1=abs(v);
            if(!h[v1])
            {
                h[v1]=true;
                a[k++]=i;
            }
            else b[cnt++]=i;
        }

        for(int i=0;i<k-1;i++)
        {
            printf("%05d %d %05d\n",a[i],e[a[i]],a[i+1]);
        }
        printf("%05d %d -1\n",a[k-1],e[a[k-1]]);

        if(cnt>0)
        {
            for(int i=0;i<cnt-1;i++)
            {
                printf("%05d %d %05d\n",b[i],e[b[i]],b[i+1]);
            }
            printf("%05d %d -1\n",b[cnt-1],e[b[cnt-1]]);
        }
        return 0;
}