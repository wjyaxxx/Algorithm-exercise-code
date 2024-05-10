#include <bits/stdc++.h>
using namespace std;
typedef pair<int ,int> PII;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
bool cmp(PII a,PII b)
{
    return a.first>b.first;
}
void solve()//打算法比赛的话，最重要的就是提示信息，位数就是信息
{
    int n,m;
    cin>>n>>m;
    vector<int> num(n);
    for(int i=0;i<n;i++) cin>>num[i];
    vector<PII> cnt(n,{0,0});
    for(int i=0;i<n;i++)
    {
        int x=num[i];
        string a=to_string(x);
        cnt[i].second=a.size();
        while(a.size()>1&&a.back()=='0'){
        cnt[i].first++;
        a.pop_back();
        }
    }
    sort(cnt.begin(),cnt.end(),cmp);
    long sum=0,sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        sum+=cnt[i].second;
        if((i&1)==0) sum1+=cnt[i].first;
        else sum2+=cnt[i].first;
    }
    long ans=sum-sum1;
    //cout<<ans<<endl;
    if(ans>=(m+1)) cout<<"Sasha"<<endl;
    else cout<<"Anna"<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}