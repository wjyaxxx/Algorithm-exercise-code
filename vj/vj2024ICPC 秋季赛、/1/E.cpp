#include <cstdio>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=21;
int w[N][N][N];
int main()
{
    //read_fast
    
    for(int i=0;i<=20;i++)
        for(int j=0;j<=20;j++)
            for(int k=0;k<=20;k++){
                if(i==0 || j==0 || k==0){
                    w[i][j][k]=1;
                    continue;
                }
                int &v= w[i][j][k];
                if(i<j && j<k){
                    v=w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                }else{
                    v=w[i-1][j][k] + w[i-1] [j-1] [k] + w[i-1] [j] [k-1] - w[i-1] [j-1] [k-1];
                }
            }
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)){
        if(a==-1 && b==-1 &&  c==-1) break;
        if(a<=0 || b<=0 || c<=0) {
            printf("w(%d, %d, %d) = %d\n",a,b,c,1);
            continue;
        }
        if(a>20 || b>20 || c>20) {
            printf("w(%d, %d, %d) = %d\n",a,b,c,w[20][20][20]);
            continue;
        }
        printf("w(%d, %d, %d) = %d\n",a,b,c,w[a][b][c]);
    }
    return 0;
}