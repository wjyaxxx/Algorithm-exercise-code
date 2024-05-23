#include <bits/stdc++.h>
using namespace std;
const int N=110;
int A[N][N],B[N][N],ans[N][N];//ans是答案矩阵
int main()
{
        int ra,ca,rb,cb;//输入矩阵的规模,r表示行，c表示列
        cin>>ra>>ca>>rb>>cb;
        
        //输入A矩阵
        for(int i=1;i<=ra;i++)
            for(int j=1;j<=ca;j++)
                cin>>A[i][j];

        for(int i=1;i<=rb;i++)
            for(int j=1;j<=cb;j++)
                cin>>B[i][j];

        //矩阵乘法

        for(int i=1;i<=ra;i++)
            for(int j=1;j<=cb;j++)
                for(int k=1;k<=ca;k++)//ca与rb相同
                    ans[i][j]+=A[i][k]*B[k][j];

        printf("相乘之后的矩阵:\n");
        for(int i=1;i<=ra;i++){
            for(int j=1;j<=cb;j++)
                cout<<ans[i][j]<<' ';
            cout<<endl;
        }
        return 0;
}