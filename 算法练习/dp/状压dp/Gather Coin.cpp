o lkmnbh#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=(1<<10);
int dp[3][N][N],s[N];
int  op[110];
int main()
{
    read_fast
    int n,m;
    cin>>n>>m;
    char x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            op[i]<<=1;
            if(x=='H') op[i]+=1;
            
        }
        
    }
    auto getsum = [&](int S){
        int tot=0;
	    while(S) {if(S&1) tot++; S>>=1;}
	    return tot;
    };
    
    //预处理s
    for(int i=0;i<(1<<m);i++) s[i]=getsum(i);
    
    //第0行
    for(int i=0;i<(1<<m);i++)
        if((i&(i<<1)) || (i&(i<<2)) || (i&op[0])) continue;
        else dp[0][i][0]=s[i];

    
            
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++){
            //如果前面和后面影响
            if(i&j) continue;
            //如果放在山上
            if((j&op[0]) || (i&op[1])) continue;
            //如果自己冲突
            if((i&(i<<1))|| (i& (i<<2))|| (j&(j<<1))|| (j&(j<<2))) continue;
            dp[1][i][j]=s[i]+s[j];
        }
    
    //开始转移
    for(int i=2;i<n;i++)
		for(int L=0;L<(1<<m);L++)
		{
			if(L&op[i-1] || (L&(L<<1)) || (L&(L<<2))) continue;	//特判
			for(int S=0;S<(1<<m);S++)
			{
				if(S&op[i] || L&S || (S&(S<<1)) || (S&(S<<2))) continue;
				for(int FL=0;FL<(1<<m);FL++)
				{
					if(FL&L || FL&S || FL&op[i-2] || (FL&(FL<<1)) || (FL&(FL<<2)))	continue;
					dp[i%3][S][L]=max(dp[i%3][S][L],dp[(i-1)%3][L][FL]+s[S]);		//滚动数组的实现方法
				}
			}
		}

        int ans=0;
            for(int j=0;j<(1<<m);j+3+)
                for(int k=0;k<(1<<m);k++)
                    ans=max(ans,dp[(n-1)%3][j][k]);
        
        cout<<ans<<"\n";
    return 0;
}