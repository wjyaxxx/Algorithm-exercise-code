#include <cstdio>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans;
int main()
{
        string a;
        cin>>a;
        int l=a.size();

        for(int i=0;i<l;i++)
        {
            int num=a[i]-'0';
            if(num&1) ans++;
        }
        cout<<ans<<endl;
        return 0;
}