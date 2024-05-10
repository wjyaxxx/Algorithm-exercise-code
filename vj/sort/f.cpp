#include <iostream>
using namespace std;
const int N=100010;
typedef long long LL;
int q[N],ans[N],tree[N];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int c){
    for(int i=x;i<=N;i+=lowbit(i)) tree[i]+=c;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i)) res+=tree[i];
    return res;
}
int quere(int l,int r)
{
    return sum(r)-sum(l-1);
}
int  main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
        q[i]++;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<quere(1,q[i]-1)<<' ';
        add(q[i],1);
    }
    return 0;
}