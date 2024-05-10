#include <bits/stdc++.h>
using namespace std;
string str;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    cin>>str;
    //if(str!="31121") return ;
    int ans=0x3f3f3f3f;
    bool ok=false;
    for(int i=1;str[i];i++)
    {
        if(str[i]=='2')
        {
            int l1=i,r1=i;
            while(l1>=0&&str[l1]!='1') l1--;
            while(r1<str.size()&&str[r1]!='1') r1++;
            if(l1==-1&&r1==str.size()) ok=true;
           

        
            int l3=i,r3=i;
            while(l3>=0&&str[l3]!='3') l3--;
            while(r3<str.size()&&str[r3]!='3') r3++;
            if(l3==-1&&r3==str.size()) ok=true;
            int len=0x3f3f3f3f;
            if(l1!=-1&&l3!=-1) len=min(len,abs(i-min(l1,l3))+1);
            if(r1!=str.size()&&r3!=str.size()) len=min(len,abs(max(r1,r3)-i)+1);
            if(l1!=-1&&r3!=str.size()) len=min(len,abs(r3-l1)+1);
            if(r1!=str.size()&&l3!=-1) len=min(len,abs(r1-l3)+1);
            ans=min(ans,len);
        }
    }
    if(ans!=0x3f3f3f3f&&!ok)cout<<ans<<endl;
    else cout<<0<<endl;
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}