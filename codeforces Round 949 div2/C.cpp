#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
void solve()
{
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    if(count(b.begin(),b.end(),-1)==n){
        for(int i=0;i<n;i++){
            b[i]=i%2+1;
        }
    }
    else{
        for(int i=0,j=-1;i<=n;i++){
            if(i==n||b[i]!=-1){
                if(j==-1){
                    for(int k=i-1;k>=0;k--){
                        b[k]=(b[k+1]==1?2:b[k+1]/2);
                    }
                }else if(i==n){
                    for(int k=j+1;k<n;k++){
                        b[k]=(b[k-1]==1?2:b[k-1]/2);
                    }
                }else{
                    int l=j,r=i;
                    while(l+1<r){
                        if(b[l]>b[r]){
                            b[l+1]=(b[l]==1?2:b[l]/2);
                            l++;
                        }else{
                            b[r-1]=(b[r]==1?2:b[r]/2);
                            r--;
                        }
                    }
                    if(b[r]!=b[l]/2&&b[l]!=b[r]/2){
                            cout<<"-1\n";
                            return ;
                        }
                }
                j=i;
            }
        }        
    }

    for(int i=0;i<n;i++){
        cout<<b[i]<<' ';
    }
    cout<<"\n";
}
int main()
{
        cinquick();
        int t;
        cin>>t;
        while(t--) solve();
        return 0;
}