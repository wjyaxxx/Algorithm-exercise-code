#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main()
{
    read_fast
    int n;
    cin>>n;
    vector<int> w(n);
    for(int i=0;i<n;i++) cin>>w[i];
    long long s=1500;
    for(int i=0;i<n;i++){
        s+=w[i];
        if(s>=4000){
            cout<<i+1<<"\n";
            return 0;
        } 
    }
    cout<<-1<<"\n";
    return 0;
}