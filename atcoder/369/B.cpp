#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    
    vector<int> l,r;
    for(int i=1;i<=n;i++){
        int x;
        char op;
        cin>>x>>op;
        if(op=='L')  l.push_back(x);
        else r.push_back(x);
    }

    int s=0;
    for(int i=0;i+1<l.size() || i+1 <r.size();i++){
        if(i+1<l.size()) s+=abs(l[i+1]-l[i]);
        if(i+1<r.size()) s+=abs(r[i+1]-r[i]);
    }

    cout<<s<<"\n";
    return 0;
}
