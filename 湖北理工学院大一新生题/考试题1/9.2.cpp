#include <bits/stdc++.h>
using namespace std;
int n;
int pre[15];
int main()
{
        cin>>n;
        for(int i=1;i<=n;i++) pre[i]=i;//先生成一个初始序列

        //用next_permutation全排列函数
        do{
            for(int i=1;i<=n;i++)
                printf("%d ",pre[i]);
            printf("\n");
        }while(next_permutation(pre+1,pre+1+n));
        return 0;
}