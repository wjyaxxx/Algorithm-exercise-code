#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
/*
    我方最优解 就是对方最差

    一、当枚举的情况
        1.存在对手输，则我赢
        2.不存在对手输，但存在我平局
        3.那就我只能输了

    二、在面临局势时，一定要改变人称
    三、直接暴搜会超时，那就改成记忆化搜索
    四、发现 奇数+奇数=偶数
            偶数+奇数=奇数
            偶数+偶数=偶数
            则我们并不关系具体数值我们之关心奇偶性
*/
int n[3];
char dp[1100][2][2];
char dfs(int cnt,int me,int you)
{
    //终止条件
    if(cnt<n[0]){
        if((me&1)==1&&(you&1)==0){
            dp[cnt][me][you]='+';
            return '+';
        }
        else if((me&1)==0&&(you&1)==1){
            dp[cnt][me][you]='-';
            return '-';
        }
        else {
            dp[cnt][me][you]='0';
            return '0';
        }
    }
    if(dp[cnt][me][you]!='\0') return dp[cnt][me][you];
    //递归调用
    bool ok=false;
    for(int i=0;i<3;i++){
        if(cnt>=n[i]) 
        {
            char res=dfs(cnt-n[i],you,(me+n[i])&1);
            if(res=='-') {
                dp[cnt][me][you]='+';
                return '+';
            }
            if(res=='0') ok=true;
        }
    }

    if(ok) {
        dp[cnt][me][you]='0';
        return '0';
    }
    else {
        dp[cnt][me][you]='-';
        return '-';
    }

}
int main()
{
        cinquick();
        for(int i=0;i<3;i++) cin>>n[i];
        sort(n,n+3);
        int x;
        for(int i=1;i<=5;i++){
            cin>>x;
            cout<<dfs(x,0,0)<<' ';
        }
        return 0;
}