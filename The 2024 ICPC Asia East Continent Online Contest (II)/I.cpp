#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

void solve(){
    int n;
    scanf("%d",&n);
    if(n % 4==0){
        printf("NO\n");
        return ;
    }
    vector<int> b(32,0);
    for(int i=31;i>=0;i--){
        int cur=(n>>i)&1;
        if(cur==0 && b[i]==0 && i-1>=0){
            b[i]=1;
            b[i-1]=-1;
        }else if(cur==0 && b[i]==-1 && i>=1){
            b[i-1]=-1;
        }else if(cur && b[i]==0) {
            b[i]=1;
        }
    }
    
    printf("YES\n");
    for(int i=0;i<32;i++){
        printf("%d ",b[i]);
        if((i+1)%8==0) printf("\n");
    }
   
}


int main()
{
    //read_fast;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}