#include <bits/stdc++.h>
#define uit unsigned int 
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
unsigned int ans;
int n,m;
string s1,s2;
const int N=3*1e6+10;
int d1[N];
int p[N<<1];
uit v[N];
uit sum1[N],sum2[N];

int main()
{
    read_fast
    cin>>n>>m;
    cin>>s1>>s2;
   
   //维护右端点的最大值
    for(int i=0,l=0,r=-1;i<n;i++){
        int k = i > r ? 1 : min(d1[r + l - i+1] , r - i + 1);
        while(i-k>=0 && i+k <n && s1[i-k]==s1[i+k]) k++;
        d1[i+1]=k--;
        if(i+k>r){
            l=i-k;
            r=i+k;
        }
    }
    
    //跑一遍Kmp
    string s=s2+'#'+s1;
    
    int sz=s.size();
    for(int i=1;i<sz;i++){
        int len=p[i-1];
        while(len && s[len]!=s[i]) len=p[len-1];
        if(s[len]==s[i]) p[i]=len+1;
        if(p[i]==s2.size()){
            v[i-p[i]-s2.size()+1]=1;//把左端点找到 
        }
    }
    
    //去找就行
    for(int i=1;i<=n;i++)v[i]+=v[i-1];
    for(int i=1;i<=n;i++)v[i]+=v[i-1];
    uit ans=0;
    int len=s2.size();
    for(int i=1;i<=n;i++){
        int R=d1[i];
        //最长回文区间
        int lf=i-(R-1),rf=i+(R-1)-m+1;
        if(rf<lf) continue;
        //cout<<lf<<' '<<rf<<"\n";
        int mid=(lf+rf)>>1;
        int res = lf<=1 ?  0 : v[lf-2];
		if((lf+rf)&1){
            ans+=(v[rf]-v[mid]-v[mid-1]+res);
        }
        else{
            ans+=(v[rf]-v[mid-1]-v[mid-1]+res);
        }
        
    }
    cout<<ans<<"\n";
    return 0;
}


