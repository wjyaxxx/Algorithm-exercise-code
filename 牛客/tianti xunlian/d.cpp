#include <iostream>
#include <cstdio>
using namespace std;
double x0, y0, x1, y1, x2,y2;

void cinquick()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{

    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    if(x1==x2&&y1==y2)
    {
        printf("%lf %lf\n",x1,y1);
        return ;
    }
    double k = -((x1 - x0) * (x2 - x1) + (y1 - y0) * (y2 - y1)) / ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double xf = k * (x2 - x1) + x1;
    double yf = k * (y2 - y1) + y1;
    printf("%lf %lf\n",xf,yf);
}
int main()
{
    //cinquick();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}