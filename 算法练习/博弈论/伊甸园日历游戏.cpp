#include <iostream>
#include <cstdio>
using namespace std;
int t,x,y,z;
int main(){
	scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&x,&y,&z);
		if((y==9 && z==30) || (y==11 && z==30) || (y+z)%2==0)
        	printf("YES\n");
		else
        	printf("NO\n");
    }
	return 0;
}