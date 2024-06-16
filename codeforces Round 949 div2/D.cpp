#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N=3*1e5+10;
int pri[N],cnt;
bool st[N];
int h[N],e[N*2],ne[N*2],idx;
void get_prime(int x){
    for(int i=2;i<x;i++){
        if(!st[i]){
           pri[cnt++]=i;
        }
            for(int j=0;pri[j]*i<x;j++){
                st[pri[j]*i]=true;
                if(i%pri[j]==0) break;
            }
    }
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

vector<int> path;
bool vis[N*2];//
void dfs(int u) {
	for (int &i = h[u]; ~i;) 
		if (!vis[i]) {
			int j = e[i];
			vis[i] = vis[i ^ 1] = 1, i = ne[i], dfs(j);
		} else
			i = ne[i];
	path.emplace_back(u);
}
void solve()
{
    int n;
    cin>>n;
    
    idx=0;
    //找到这个图中的这个符合的点m
    //int m=1;
    //while(n-1>(m % 2 == 1 ? m * (m + 1) / 2 : m * m / 2 + 1)) m++; 
    int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if ((mid & 1) && mid * (mid + 1) / 2 >= n - 1) r = mid;
		else if ((mid % 2 == 0) && mid * mid / 2 + 1 >= n - 1) r = mid;
		else l = mid + 1;
	}
    int m=l;
    fill(h,h+m,-1);
    //cout<<m<<endl;
    for(int i=0;i<m;i++)
        for(int j=i;j<m;j++)
            if((m&1)  ||j!=i+1|| i%2==0){
                //cout<<i<<' '<<j<<endl;
                add(i,j),add(j,i);
            }

    path.clear();
    fill(vis,vis+idx,0);
    dfs(0);
    reverse(path.begin(),path.end());

    for(int i=0;i<n;i++) cout<<pri[path[i]]<<' ';
    cout<<"\n";

}
signed main()
{
        ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);

        get_prime(N);
        
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}