#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
set<int> L,R;
int n;
const int N=50010;
int q[N],sum[N];
int ans;
int main()
{
        cinquick();
        cin>>n;
        for(int i=1;i<=n;i++) cin>>q[i];
        //遍历前缀
        //枚举前缀，然后让后缀中能不能找到该前缀
        //在添加后缀时，如果不是前缀中的数
        for(int i=1,j=n;i<=n;i++){
            L.insert(q[i]);            
            while(j>=0&&L.find(q[j])!=L.end()){
                R.insert(q[j--]);
                sum[R.size()]++;//该前缀对应的后缀区间多了一个
            }
            ans+=sum[L.size()];
        }
        cout<<ans<<endl;
        return 0;
}