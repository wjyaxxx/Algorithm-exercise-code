#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    //read_fast
    int n;
    cin>>n;
    double i;
    i=(double)n;
    double s=(i*(i+1)*(2*i+1))/6;
    printf("%.15g",s);
    return 0;
}