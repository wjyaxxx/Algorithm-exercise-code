#include <bits/stdc++.h>
#define read_fast std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
using namespace std;
int main() {
    read_fast;
    int n, m;
    cin >> n >> m;
   vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    bool f=false;
    for(int i=0;i<n;i++){
        int j=lower_bound(a.begin()+i+1,a.end(),m-a[i])-a.begin();
        if(j!=n && a[j]==m-a[i]){
            f=true;
            cout<<a[i]<<' '<<m-a[i]<<"\n";
            break;
        }
    }
    if (!f) {
        cout << "No Solution" << endl;
    }
    
    return 0;
}