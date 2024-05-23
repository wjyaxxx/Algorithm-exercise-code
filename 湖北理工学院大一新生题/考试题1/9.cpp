#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n;
int pre[N],st[N];//每个位置存的数是多少,st用于判断哪些被用了
void dfs(int u)
{   
    if(u>n){
        //此时已经枚举完了
        for(int i=1;i<=n;i++)
            printf("%d ",pre[i]);
        printf("\n");

        return ;
    }

    for(int i=1;i<=n;i++){
        if(!st[i]){ //i没有被用到
            pre[u]=i;
            st[i]=true;
            dfs(u+1);
            //回溯,恢复现场
            pre[u]=0;
            st[i]=false;
        }
    }
}
int main()
{
        
        cin>>n;
        dfs(1);
        return 0;
}