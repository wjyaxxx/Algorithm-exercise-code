#include <bits/stdc++.h>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
const double INF=1e20;
const int N=1e6+10;
int sgn(double a){ //误差 
	if(fabs(a)<eps) return 0;
	return a>0?1:-1;
}
int dcmp(double a,double b){//两double比较 
	if(fabs(a-b)<eps) return 0;
	return a>b?1:-1;
}
struct point{//点的定义 ，点和向量未做区分 
	double x,y;
	point(){}
	point(int x,int y):x(x),y(y){}
	point operator+(point b){ return point(x+b.x,y+b.y);}
	point operator-(point b){ return point(x-b.x,y-b.y);}
	point operator*(double k){ return point(x*k,y*k);}
	point operator/(double k){ return point(x/k,y/k);}
	bool operator==(point b){return sgn(x-b.x)==0&&sgn(y-b.y)==0;}
	bool operator<(point b){
		return sgn(x-b.x)<0||sgn(x-b.x)==0&&sgn(y-b.y)<0;
	}
};
double dot(point a,point b){return a.x*b.x+a.y*b.y;}//点积 
double cross(point a,point b){return a.x*b.y-a.y*b.x;}//叉积 
double dis(point a,point b){return hypot(a.x-b.x,a.y-b.y);}//两点距离 
double len(point a){return dis(a,point(0,0));}// 向量长度 
double len2(point a){return dot(a,a);}//向量长度平方 
double angle(point a,point b){return acos(dot(a,b)/len(a)/len(b));}//求两向量夹角 
double area(point a,point b,point c){return fabs(cross(b-a,c-a))/2;}//求abc面积 
point rotate(point a,double rad){return point(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));}//旋转向量 
point normal(point a){return point(-a.y/len(a),a.x/len(a));}//a的单位法向量 
bool parallel(point a,point b){return sgn(cross(a,b))==0;}//判断两向量是否平行 
struct line{//直线的定义 ，直线和线段未做区分 
	point p1,p2;//p1->p2
	line(){}
	line(point p1,point p2):p1(p1),p2(p2){}//两点表示 
	line(point p,double rad){//向量表示 
		p1=p;
		if(sgn(rad-pi/2)==0) p2=p1+point(0,1);
		else p2=p1+point(1,tan(rad));
	}
	line(double a,double b,double c){//ax+by+c 
		if(sgn(a)==0){
			p1=point(0,-c/b);
			p2=point(1,-c/b);
		}
		else if(b==0){
			p1=point(-c/a,0);
			p2=point(-c/a,1);
		}
		else{
			p1=point(0,-c/b);
			p2=point(1,(-c-a)/b);
		}
	}
};
int point_line_relation(point p,line v){//点和直线的关系 
	int c=sgn(cross(p-v.p1,v.p2-v.p1));
	if(c<0) return -1;//左侧 
	if(c>0) return 1;//右侧 
	return 0;//在线上 
}
bool point_on_seg(point p,line v){//点是否在线段上 
	return point_line_relation(p,v)==0&&sgn(dot(p-v.p1,p-v.p2))<=0;
}
double dis_point_line(point p,line v){//点到直线的距离 
	return fabs(cross(p-v.p1,p-v.p2))/dis(v.p1,v.p2);
}
point point_line_proj(point p,line v){//点往直线作垂线的夹角 
	double k=dot(v.p2-v.p1,p-v.p1)/len2(v.p2-v.p1);
	return v.p1+(v.p2-v.p1)*k;
}
point point_line_symmetry(point p,line v){//点关于直线的对称点 
	point p1=point_line_proj(p,v);
	return point(2*p1.x-p.x,2*p1.y-p.y);
}
double dis_point_seg(point p,line v){//点到线段的距离 
	if(sgn(dot(p-v.p1,v.p2-v.p1))<0||sgn(dot(p-v.p2,v.p1-v.p2))<0){
		return min(dis(p,v.p1),dis(p,v.p2));
	}
	return dis_point_line(p,v);
}
int line_relation(line v1,line v2){//直线之间的关系 
	if(sgn(cross(v1.p2-v1.p1,v2.p2-v2.p1))==0){
		if(point_line_relation(v1.p1,v2)==0) return 1;//重合 
		return 0;//平行 
	}
	return 2;//相交 
}
point cross_point(line v1,line v2){//直线的交点 
	double s1=fabs(cross(v1.p2-v1.p1,v2.p1-v1.p1));
	double s2=fabs(cross(v1.p2-v1.p1,v2.p2-v1.p1));
	return point(v2.p1.x*s2+v2.p2.x*s1,v2.p1.y*s2+v2.p2.y*s1)/(s1+s2);
}
bool cross_segment(line v1,line v2){//线段是否相交 
	point a=v1.p1,b=v1.p2,c=v2.p1,d=v2.p2;
	double c1=sgn(cross(b-a,c-a)),c2=sgn(cross(b-a,d-a));
	double d1=sgn(cross(d-c,a-c)),d2=sgn(cross(d-c,b-c));
	if(c1==0||c2==0||d1==0||d2==0) return 1;//算上端点，若不算端点，注释这一行 
	return c1*c2<0&&d1*d2<0;
}
//多边形
int point_in_polygon(point pt,point *p,int t){//求多边形和点的位置关系 0 在外部 ，1 在内部，2在边上，3在顶点上 
	for(int i=0;i<t;i++){
		if(pt.x==p[i].x&&pt.y==p[i].y) return 3;
	}
	for(int i=0;i<t;i++){
		if(point_on_seg(pt,line(p[i],p[(i+1)%t]))) return 2;
	}
	int sum=0;
	for(int i=0;i<t;i++){
		int j=(i+1)%t;
		int c=sgn(cross(pt-p[j],p[i]-p[j]));
		int v=sgn(p[i].y-pt.y);
		int u=sgn(p[j].y-pt.y);
		if(c>0&&u<0&&v>=0) sum++;
		if(c<0&&u>=0&&v<0) sum--;
	}
	return sum!=0;
}
double polygon_area(point *a,int t){//多边形面积 
	double ans=0;
	for(int i=0;i<t;i++){
		ans+=cross(a[i],a[(i+1)%t]);
	}
	return ans/2;
}
point polygin_center(point *p,int n){//多边形重心 
	point ans=point(0,0);
	if(polygon_area(p,n)==0) return ans;
	for(int i=0;i<n;i++){
		ans=ans+(p[i]+p[(i+1)%n])*cross(p[i],p[(i+1)%n]);
	}
	return ans/polygon_area(p,n)/6;
}
int convex_hull(point *p,int n,point *ch){//凸包 
	n=unique(p,p+n)-p;
	sort(p,p+n);
	int v=0;
	for(int i=0;i<n;i++){
		while(v>1&&sgn(cross(ch[v-1]-ch[v-2],p[i]-ch[v-2]))<=0) v--;
		ch[v++]=p[i];
	}
	int j=v;
	for(int i=n-2;i>=0;i--){
		while(v>j&&sgn(cross(ch[v-1]-ch[v-2],p[i]-ch[v-2]))<=0) v--;
		ch[v++]=p[i];
	}
	if(n>1) v--;
	return v;
}
bool cmp_y(point a,point b){return sgn(a.y-b.y)<0;}
double closest_pair(point *p,int l,int r){//最近点对 使用前务必保证已经按x坐标排序 
	double dist=INF;
	if(l==r) return dist;
	if(l==r-1) return dis(p[l],p[r]);
	int mid=l+(r-l)/2;
	double d1=closest_pair(p,l,mid);
	double d2=closest_pair(p,mid+1,r);
	dist=min(d1,d2);
	vector<point> t;
	for(int i=l;i<=r;i++){
		if(fabs(p[mid].x-p[i].x)<=dist) t.push_back(p[i]);
	}
	sort(t.begin(),t.end(),cmp_y);
	for(int i=0;i<t.size();i++){
		for(int j=i+1;j<t.size();j++){
			if(t[j].y-t[i].y>=dist) break;
			dist=min(dist,dis(p[i],p[j]));
		}
	}
	return dist;
}
double get_longest(point *ch,int t){
	double mx=-1;
	int j=2;
	for(int i=0;i<t;i++){
		mx=max(mx,len2(ch[i]-ch[(i+1)]));
		while(sgn(cross(ch[(i+1)]-ch[i],ch[j]-ch[i])-cross(ch[(i+1)]-ch[i],ch[(j+1)]-ch[i]))<0) j=(j+1)%t;
		mx=max(mx,max(len2(ch[i]-ch[j]),len2(ch[(i+1)]-ch[j])));
	}
	return mx;
}
point a[M+5],ch[M+5],b[M+5];
void solve(){
	int na,nb;
	cin>>nb;
	double ans=0;
	for(int i=0;i<nb;i++){
		cin>>b[i].x>>b[i].y;
	}
	for(int i=0;i<nb;i++){
		ans+=len(b[i]-b[(i+1)%nb]);
	}
	cin>>na;
	for(int i=0;i<na;i++) cin>>a[i].x>>a[i].y;
	int v=convex_hull(a,na,ch);
	long long d=get_longest(ch,v);
	ans+=sqrtl(d)*2ll*pi;
	cout<<fixed<<setprecision(10)<<ans<<'\n';	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ins=1;
	cin>>ins;
	while(ins--) solve();
	return 0;
}