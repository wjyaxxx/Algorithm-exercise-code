#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        //cinquick();
        int n1,n2,n;
        while(cin>>n1>>n2>>n){
            if(!(n1||n2||n)) break;
            priority_queue<int> lessest;
            priority_queue<int,vector<int>,greater<int>> greatest;
            LL sum=0;
            int x;
            for(int i=1;i<=n;i++){
                scanf("%d",&x);
                sum+=x;
                greatest.push(x);
                lessest.push(x);
                if(greatest.size()>n1) greatest.pop();
                if(lessest.size()>n2) lessest.pop();
            }
            for(int i=1;i<=n1;i++){
                sum-=greatest.top();
                greatest.pop();
            }      

            for(int j=1;j<=n2;j++){
                sum-=lessest.top();
                lessest.pop();
            }
            
            printf("%.6lf\n",sum*1.0/(n-n1-n2));
        }
        return 0;
}