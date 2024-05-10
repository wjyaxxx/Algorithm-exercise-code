#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define pq priority_queue
const int N=200+10;
const int maxn=200000+10;

struct node
{
	string name;
	ll v;
	friend bool operator <(node a,node b)
	{
		if (a.v==b.v)
			return a.name>b.name;
		return a.v<b.v;
	}
};

//string s[maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> s;
	string x;

	int cnt=0;
	while(cin>>x)
	{
		cnt++;
		s.push_back(x);
	}

	unordered_map<string,ll> mp;
	for (int i=0; i<cnt; i++)
		mp[s[i]]+=cnt-i;

	pq<node> q;

	bool sign=0;
	ll chk=0;

	for (auto i:mp)
	{
		if (i.first=="NiLu")
		{
			sign=1;
			chk=i.second;
		}
		q.push({i.first,i.second});
	}

	int res=0;

	int tik=0;

	vector<node> v(10);

	while(!q.empty()&&tik<5)
	{
		auto t=q.top();
		q.pop();
		if (t.name!="NiLu"&&t.name!="LeiDianJiangJun"&&t.name!="KeLi"&&t.name!="ZhongLi"&&t.name!="naxida"
		        &&t.name!="basketball"&&t.name!="rap"&&t.name!="sing"&&t.name!="jump"&&t.name!="alcohol")
			res++;
		if (t.name=="NiLu")
			sign=1;
		tik++;
		v[tik]=t;
	}
    cout<<res<<endl;
	if (res>=3&&sign)
		cout<<"Ni Zui Hao Shi"<<endl;
	else if (res>=3&&!sign)
		cout<<"Ni Gan Ma ?"<<endl;
	else if (res<3&&sign)
	{
		cout<<"lanbai, get up and work!"<<endl;
		int ans=0;
		for (int i=1; i<=tik; i++)
		{
            cout<<v[i].name<<' '<<v[i].v<<endl;
			if (v[i].name!="NiLu"&&v[i].name!="LeiDianJiangJun"&&v[i].name!="KeLi"&&v[i].name!="ZhongLi"&&v[i].name!="naxida"
			        &&v[i].name!="basketball"&&v[i].name!="rap"&&v[i].name!="sing"&&v[i].name!="jump"&&v[i].name!="alcohol")
				;
			else if (v[i].name!="Nilu")
				ans+=v[i].v;
		}
		cout<<ans-chk<<endl;
	}
	else
	{
		for (int i=1; i<=tik; i++)
			cout<<v[i].name<<" "<<v[i].v<<endl;
	}
	return 0;
}



