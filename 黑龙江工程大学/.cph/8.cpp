#include <bits/stdc++.h>
using namespace std;
const int N=2510;
int q[N],cnt[N],s[N];
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void add(int l,int r,int c)
{
    cnt[l]+=c;
    cnt[r+1]-=c;

}
int main()
{
        cinquick();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i],s[i]=s[i-1]+q[i];
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                {
                    int cnt1=s[j]-s[i-1];
                    int len=(j-i+1);
                    int cnt0=len-cnt1;
                    if(cnt0>cnt1){
                        res=max(res,cnt0-cnt1);      
                    }
                }

        
        int res1=0;
        for(int i=1;i<=n;i++)
            if(q[i])
                res1++;
        if(res1==n) cout<<n-1<<endl;
        else cout<<res1+res<<endl;
        return 0;
}