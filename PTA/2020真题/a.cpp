#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
      cinquick();
      int z[3][3];		//用于储存彩票数字 
	int sum=0,num=45;	//sum储存玩家挑选方向的数字合计，num为1到9的和 
	int money[]={10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&z[i][j]);
			num-=z[i][j];
		}
	}
	//用于找到0位置的是数字几 
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(z[i][j]==0)
				z[i][j]=num;
		}
	}
	//输出玩家挑选的3个数 
	for(int i=0;i<3;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",z[x-1][y-1]);
	}
	//获取玩家挑选的方向并计算该方向的和 
	int n;
	scanf("%d",&n);
	if(n<=3)
		sum=z[n-1][0]+z[n-1][1]+z[n-1][2];
	else if(n<=6)
		sum=z[0][n-4]+z[1][n-4]+z[2][n-4];
	else if(n==7)
		sum=z[0][0]+z[1][1]+z[2][2];
	else
		sum=z[0][2]+z[1][1]+z[2][0];
	//输出数字合计对应的金币 
	printf("%d",money[sum-6]);


        return 0;
}