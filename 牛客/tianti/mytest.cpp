#include <bits/stdc++.h>
using namespace std;
const int N=500010;
typedef pair<string,int> PII;
#define x first
#define y second
typedef long long LL;
string ans[200005];
int l,l1;
int lin,fei;
string wjy[]={"basketball","rap","sing","jump","alcohol","NiLu","LeiDianJiangJun","KeLi","ZhongLi","naxida"};
PII mp[200005];
bool check1(string x)
{
	for(int i=0;i<10;i++)
		if(x==wjy[i])
			return true;
	return false;
}
int find(string s)
{
	for(int i=0;i<l1;i++)
	{
		if(mp[i].x==s) return i;
	}
	return -1;
}
bool cmp(PII a,PII b)
{
	if(a.y!=b.y) return a.y>b.y;
	else return a.x<b.x;
}
int main()
{
	ios::sync_with_stdio(0);
	 cin.tie(0),cout.tie(0);
	
	string a;
	getline(cin,a);
	string res="";
	for(int i=0;i<a.size();i++)
	{
		
		if(a[i]==' ')
		{
			ans[l++]=(res);
    
			if(res=="NiLu") lin++;
			else if(!check1(res)) ;
			res="";
		}
		else{
			res+=a[i];
		}
	}
	ans[l++]=res;
	for(int i=0;i<l;i++)
	{
		int idx=find(ans[i]);
		if(idx!=-1)
		{
			mp[idx].y+=(l-i);
		}
		else mp[l1++]={ans[i],l-i};
	}
	sort(mp,mp+l1,cmp);
    for(int i=0;i<5;i++)
    {
        if(!check1(mp[i].x)) fei++;  
    }
	if(fei>=3&&lin)
	{
		cout<<"Ni Zui Hao Shi"<<endl;
	}
	else if(fei>=3)
	{
		cout<<"Ni Gan Ma ?"<<endl;
	}
	else if(lin)
	{
		LL sum=0,sum1=0;
        int cnt=0;
		for(int i=0;i<5;i++)
		{
			string s=mp[i].x;
            int v=mp[i].y;
            cout<<s<<' '<<v<<endl;
            if(s=="NiLu") sum1+=v;
            if(check1(s)) sum+=v;
            
		}
		cout<<"lanbai, get up and work!"<<endl;
		cout<<sum<<endl;
	}
	else {
		for(int i=0;i<5;i++)
        {
			string s=mp[i].x;
            int v=mp[i].y;
			cout<<s<<' '<<v<<endl;
        }
      
	}
	return 0; 
}

