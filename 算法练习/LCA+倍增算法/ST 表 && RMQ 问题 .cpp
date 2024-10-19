#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
class ST {
    using ll=long long;
     private:
         vector<vector<ll>> st;
         int n;
         bool cmp;
     public:
         ST(const vector<ll>& initVector,bool cmp1) {
             n = initVector.size();
             cmp=cmp1;
             st.resize(n, vector<ll>(__lg(n)+1));
             // 初始化st表的第0层
             for (int i = 0; i < n; ++i) {
                 st[i][0]=initVector[i];
             }
             // 动态规划填充st表
             for (int j = 1; j <= __lg(n); ++j) {
                 for (int i = 0; i+(1<<j) <= n; ++i) {
                    if(!cmp)
                    st[i][j]=max(st[i][j - 1], st[i+(1<<(j - 1))][j - 1]);
                    else st[i][j]=min(st[i][j - 1], st[i+(1<<(j - 1))][j - 1]);
                 }
             }
         }
         int query(int l, int r) {
             int k = __lg(r - l+1);
             if(!cmp)
             return max(st[l][k], st[r-(1<<k)+1][k]);
             else return min(st[l][k], st[r-(1<<k)+1][k]);
         }
        

     };
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    vector<long long> a(n);   
    for(int i=0;i<n;i++) cin>>a[i];
    ST st1(a,false);
    int l,r;
    while(m--){
        cin>>l>>r;
        l--;
        r--;
        cout<<st1.query(l,r)<<"\n";
    }
    return 0;
}