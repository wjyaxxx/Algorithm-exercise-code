#include <iostream>
#include <ctime>
#include <random>
using namespace std;
int main() {
 
    default_random_engine e;
    uniform_int_distribution<int> u(-10,10); // 左闭右闭区间
    uniform_int_distribution<int> u1(0,2);
    e.seed(time(0));
    
    for(int i=1;i<=20;i++)
    {
        cout<<u(e)<<' ';
    }

    return 0;
}

      