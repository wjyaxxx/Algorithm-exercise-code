//找出所有的四位数
#include <stdio.h>
#include <iostream>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    for(int i=1000;i<10000;i++){
        int s1=0,s2=0,s3=0;
        int n=i;
        while(n){
            s1+=n%10;
            n/=10;
        }
        n=i;
        while(n){
            s2+=n%12;
            n/=12;
        }
        n=i;
        while(n){
            s3+=n%16;
            n/=16;
        }      
        if(s1==s2 && s2==s3) cout<<i<<"\n";       
    }
    return 0;
}