#include <bits/stdc++.h>
using namespace std;
vector<int> A;
    void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();

        string a;
        cin>>a;
        int l=a.size();
        for(int i=l-1;i>=0;i--) A.push_back(a[i]-'0');

        vector<int> c;
        int r=0;

        for(int i=A.size()-1;i>=0;i--)
        {
            r=r*10+A[i];
            c.push_back(r/2023);
            r%=2023;
        }
        cout<<r<<endl;
        return 0;
}