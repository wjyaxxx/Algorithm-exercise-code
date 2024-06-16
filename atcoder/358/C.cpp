#include <bits/stdc++.h>
using namespace std;
int n,  k;
int a[400];
int dp[1 << 21];
int main()
{
	cin >> n>> k;
    char x;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			// 读入每包糖果
			cin >> x;
            if(x=='o')
			    a[i] |= 1 << (j - 1);
		}
	}

	memset(dp, 0x3f, sizeof(dp)); // 初始化dp为最大值

	dp[0] = 0; // 最小访问次数

	for (int i = 1; i <= n; i++)//访问每包糖果
	{
		for (int j = 0; j < (1 << k); j++)//访问每个状态
		{
			// 如果最小次数已经大于n（买不到喽）
			if (dp[j] > n){
				continue;
			}
			// 将原来得到糖果所需的次数与当前次数+1（要这袋糖果）比较并赋值
			dp[j | a[i]] = min(dp[j | a[i]], dp[j] + 1);
		}
	}

	// (1<<m)-1 表示都是1 也就是都买到的状态。
	if (dp[(1 << k) - 1] > n){
        		cout << -1;
	}//>n就买不到了

	else{
        		cout << dp[(1 << k) - 1];
	}//直接输出次数

	return 0;
}

