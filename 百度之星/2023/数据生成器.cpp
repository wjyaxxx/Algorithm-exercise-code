#include <bits/stdc++.h>
#include <cstdlib>

#include <ctime>
using namespace std;
typedef long long LL;
int f(int a,int b){
    return (rand()%(b-a+1))+a;
}
int main()
{
        srand((unsigned)time(NULL));
       
        
        int N=f(1,10);
        int M=f(0,10);
        printf("%d %d\n",N,M);
        while(N--){
            printf("%d %d\n",f(0,10),f(0,10));
        }
        
        return 0;
}