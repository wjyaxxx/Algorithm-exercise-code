#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double x;
    vector<double> a;
    for(int i=1;i<=8;i++){
        cin>>x;
        a.push_back(x);
    }
    for(auto& m:a){
        cout<<m<<' ';
    }
    return 0;
}