#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
struct point{
    double x,y;
};
double sqr(double x){
    return x*x;
}
double dis(point a,point b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
int main()
{
    read_fast
    point A,B;
    while(~scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y)){
        printf("%.2lf\n",dis(A,B));
    }
    return 0;
}