#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n;
int main()
{
    read_fast
    cin>>n;
    vector<vector<int>> goal(2,vector<int>(3));
    for(int i=1;i<=n;i++){
        int id,g;
        cin>>id>>g;
        g--;
        goal[id][g]+=1;
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++){
         cout<<goal[i][j]<<" \n"[j==2];
    }
    for(int k=0;k<3;k++){
        if(goal[0][k]==goal[1][k]) continue;
        if(goal[0][k]>goal[1][k]) 
            cout<<"The first win!"<<"\n";
        else cout<<"The second win!"<<"\n";
        break;
    }
    return 0;
}