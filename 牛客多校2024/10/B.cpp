#include <bits/stdc++.h>
using namespace std;
#define  read_fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
unordered_map<string,int>mp;
int idx,n,m;
const int N=1010;
string tree[N];

// string Q(int u,int ans,int idx, string s){
//     if(anss!="") return "";
//     int idx1=-1,idx2=-1,idx3=-1;
//     stack<int> a,b;
//     for(int i=0;i<s.size();i++){
//         if(s[i]=='<') a.push(i);
//         if(s[i]==',') b.push(i);
//         if(s[i]=='>'){
//             if(a.size()==1) {
//                 idx1=a.top(),idx2=b.top(),idx3=i;
//                 break;
//             }
//             else{
//                 a.pop();
//                 b.pop();
//             }
//         }
//     }
    
//     if(idx1==-1){
//         //说明此时一定是类型
//         //tree[idx][u]=s;
//         if(ans==u) anss=s;
//         return s;
//     }
//     string l=Q(u<<1,ans,idx,s.substr(idx1+1,idx2-idx1-1));
//     string r=Q(u<<1|1,ans,idx,s.substr(idx2+1,idx3-idx2-1));
    
//     string z= "pair<"+l+","+r+">";
//     if(ans==u){
//         anss=z;
//     }
//     return z;
// }
string Q(int l, string s){
    
    int idx1=-1,idx2=-1,idx3=-1;
    stack<int> a,b;
    for(int i=0;i<s.size();i++){
        if(s[i]=='<') a.push(i);
        if(s[i]==',') b.push(i);
        if(s[i]=='>'){
            if(a.size()==1) {
                idx1=a.top(),idx2=b.top(),idx3=i;
                break;
            }
            else{
                a.pop();
                b.pop();
            }
        }
    }
    
    if(idx1==-1){
        return s;
    }
    if(l==1)
    return s.substr(idx1+1,idx2-idx1-1);
    else return s.substr(idx2+1,idx3-idx2-1);
    
}
int main()
{
    read_fast
    cin>>n>>m;
    string type,name;
    for(int i=1;i<=n;i++){
        cin>>type>>name;
        name.pop_back();
        mp[name]=++idx;
        tree[idx]=type;
        //tree[idx][1]=Build(1,idx,type);
    }
    // for(int i=1;i<=10;i++){
    //     cout<<tree[1][i]<<"\n";
    // }
    string x;
    for(int i=1;i<=m;i++){
        cin>>x;
        string st="";
        int z=0;
        while(z<x.size() && x[z]!='.'){
            st+=x[z];
            z++;
        }
        int id=mp[st];
        if(z==x.size()) cout<<tree[id]<<"\n";
        else{
            int u=1,l=z;
            string anss=tree[id];
            for(int r=z+1;r<x.size();r++){
                if(x[r]=='.'){
                    if(x[l+1]=='f') anss=Q(1,anss);
                    else anss=Q(0,anss);
                    l=r;
                }
            }
            if(x[l+1]=='f') anss=Q(1,anss);
            else anss=Q(0,anss);
            cout<<anss<<"\n";
        }

        
    }
    return 0;
}