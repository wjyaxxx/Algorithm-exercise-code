#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<vector>
using namespace std;
long long i=0,b[500010],m=1000000007;
int main(){
	
//	freopen("in.txt", "r", stdin);      //读入数据生成器造出来的数据
//	freopen("正解.txt", "w", stdout);	
	int q;
    scanf("%d",&q);
    
    b[0]=0;
    while(q--){
        long long x,y;
        scanf("%d%d",&x,&y);
        i=i-x;
        if(i<0)i=0;
        i++;
        b[i]=b[i-1]+i*y%m;
        printf("%d\n",b[i]%m);
    }
	return 0;
}


