#include <bits/stdc++.h>
using namespace std;
const int N=1010;
double g[N][N];
bool m[N];
int n,mp;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int read(){//读入一个人，记录它的性别并返回编号
	string s;cin>>s;
	bool man=false;
	if(s[0]!='-')man=true;
	else s=s.substr(1,s.size()-1);
	int x=0;
	for(int i=0;i<s.size();++i){
		x*=10;
		x+=s[i]-'0';
	}
	m[x]=man;
	return x;
}
double find(int x){//查找某个人的最大亲密度
	double res=-1;
	for(int i=0;i<n;++i){
		if(m[x]!=m[i]){
			res=max(res,g[x][i]);
		}
	}
	return res;
}
void out(int x){//输出一个人
	if(m[x]==false)cout<<"-";
	cout<<x;
}
int main()
{
        cinquick();
        
        cin>>n>>mp;
        for(int i=1;i<=mp;i++)
        {
            int k;
            cin>>k;
            vector<int> a[2];//a[0]为男人，a[1]为女人
            for(int j=1;j<=k;j++)
            {
                int x=read();
                if(m[x]) a[0].push_back(x);
                else a[1].push_back(x);
            }

            for(int c=0;c<a[0].size();c++)
            {
                for(int z=0;z<a[1].size();z++)
                {
                    g[a[0][c]][a[1][z]]+=1*1.0/k;
                    g[a[1][z]][a[0][c]]+=1*1.0/k;
                }
            }
        }
        int x=read();
        int y=read();
        double mx=find(x),my=find(y);
    
        if(mx==g[x][y]&&mx==my) 
        {
            out(x);
            cout<<' ';
            out(y);
        }
        else
        {
            for(int i=0;i<n;++i){
			if(m[i]!=m[x]&&g[x][i]==mx){
				out(x);cout<<" ";out(i);cout<<endl;
			    }
		    }
		    for(int i=0;i<n;++i){
			    if(m[i]!=m[y]&&g[y][i]==my){
				    out(y);cout<<" ";out(i);cout<<endl;
			    }
		    }
        }

        return 0;
}