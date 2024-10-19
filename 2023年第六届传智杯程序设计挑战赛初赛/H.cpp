#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
};
//计算两者距离
double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
//两点求向量
Point AB(Point a,Point b){
    return Point(b.x-a.x,b.y-a.y);
}
Point fAB(Point AB){
    return Point(AB.y,-AB.x);
}
Point dan(Point l){
    double len=sqrt(l.x*l.x + l.y*l.y);
    return Point(l.x/len,l.y/len);
}
Point z(Point p,Point l,double len){
    return Point(p.x+l.x*len , p.y+l.y*len);
}
int main()
{
    //read_fast
    double r,s;
    Point o,p;
    cin>>r;
    cin>>o.x>>o.y;
    cin>>s;
    cin>>p.x>>p.y;
    double maxs;
    //与圆心相同
    if (o.x == p.x && o.y == p.y) {
        maxs = r * r;
        if(maxs<s){cout<<-1;return 0;}
        Point p1(p.x - r, p.y);
        Point p2(p.x + r, p.y);
        Point p3(p.x, p.y + r);
        printf("%.7f %.7f %.7f %.7f %.7f %.7f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
        return 0;
    }


    double dis1=dis(o,p);
    
    if(dis1*2<r){
        //这个等腰三角形
        double di=sqrt(r*r-dis1*dis1);
        maxs=(dis1+r)*di;
    }else{
        //等边三角形
        maxs=3.0/4*sqrt(3.0)*r*r;
    }
    if(maxs<s){
        cout<<-1<<"\n";
        return 0;
    }
    Point po=AB(p,o);
    Point fpo=fAB(po);
    po=dan(po),fpo=dan(fpo);
    //算坐标
    if(dis1*2<r){
        double len=sqrt(r*r-dis1*dis1);
        Point p1=z(o,po,r);
        Point p2=z(p,fpo,len);
        Point p3=z(p,fpo,-len);
        printf("%.7f %.7f %.7f %.7f %.7f %.7f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    }else{
        Point p1=z(o,po,r);
        Point m=z(o,po,-r/2);
        double len=sqrt(3.0)*r/2;
        Point p2=z(m,fpo,len);
        Point p3=z(m,fpo,-len);
        printf("%.7f %.7f %.7f %.7f %.7f %.7f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    }
    return 0;
}