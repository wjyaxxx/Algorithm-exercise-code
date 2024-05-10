#include<iostream>
#include <cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
bitset<1010> s[10010];
int n,q;

int main()
{
        
        cin>>n;
        for(int i=1;i<=n;i++){
            int k,x;
            scanf("%d",&k);
            for(int j=1;j<=k;j++){
                scanf("%d",&x);
                s[x][i]=1;
            }
        }
        cin>>q;
        int x,y;
        while(q--){
            scanf("%d%d",&x,&y);
            if((s[x]&s[y]).count()) printf("Yes\n");
            else printf("No\n");
        }
        return 0;
}