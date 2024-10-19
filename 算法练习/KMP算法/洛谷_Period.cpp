#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
void solve(int n)
{
    string s;
    cin>>s;
    
    vector<int> pi(n);
    
    for(int i=1;i<n;i++){
        int len=pi[i-1];
        while(len>0 && s[len]!=s[i]) len=pi[len-1];
        if(s[i]==s[len]) pi[i]=len+1;
    }
    //对于循环的字串来说，只要前后缀相同，就必然pi[i]大于0
    //只需要判断循环节的次数是否大于2
    for(int i=0;i<n;i++){
        if(pi[i]*2>=(i+1)){
            int clen=pi[i]*2-(i+1);
            int xlen=pi[i]-clen;
            if((i+1)%xlen==0) cout<<(i+1)<<' '<<(i+1)/xlen<<"\n";
        }
    }
    
}
int main()
{
    //read_fast;
    int n;
    int m=0;
    while(cin>>n && n){
        m++;
        printf("Test case #%d\n",m);
        solve(n);
        cout<<"\n";
    }
    
    return 0;
}