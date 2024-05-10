#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int s;
int e[N],ne[N];
int ad[N];
int b[N];
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
        for(int i=st;i!=-1;i=ne[i])
        {
            s++;
            ad[s]=i;
        }
        int l=1,r=s,k=0;
        while(l<r)
        {
            b[++k]=ad[r--];
            b[++k]=ad[l++];
        }
        if(l==r) b[++k]=ad[r];

        for(int i=1;i<s;i++)
        {
            printf("%05d %d %05d\n",b[i],e[b[i]],b[i+1]);
        }
        printf("%05d %d -1\n",b[s],e[b[s]]);
        return 0;
}