#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int num[N],sum[N];
int main()
{
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            sum[i]=sum[i-1]+num[i];//sum[i]存的是前面i个数的前缀和
        }   

        int q;//q次询问
        cin>>q;
        int l,r;
        while(q--){
            scanf("%d%d",&l,&r);//左右端点
            printf("%d\n",sum[r]-sum[l-1]);
        }
        return 0;
}