#include <bits/stdc++.h>
using namespace std;
const int N=50010;
typedef long long LL;
int q[N],tmp[N];
int n;
LL ans;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void memge_sort(int l,int r)
{
    if(l>=r) return ;
    int mid=(l+r)>>1;
    memge_sort(l,mid),memge_sort(mid+1,r);

    //归并
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else{
            tmp[k++]=q[j++];
            ans+=(mid-i+1);
        }
    }

    while(i<=mid){
    tmp[k++]=q[i++];
    }
    while(j<=r) tmp[k++]=q[j++];

    for(int i=l,s=0;i<=r;i++,s++)
        q[i]=tmp[s];
}

int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i];
        memge_sort(1,n);
        cout<<ans<<endl;
        return 0;
}