#include <bits/stdc++.h>
using namespace std;
void cinquick()
{
       ios::sync_with_stdio(0);
       cin.tie(0);
       cout.tie(0);
}
int main()
{
        cinquick();
        //c语言写法
        //srand((unsigned int)time(NULL));//time(NULL) 返回时间戳（时差，以32或64位int来存储）
                                        //srand函数是随机数种子 即他的种子是一个（unsigned int）
        // srand((unsigned int)100);//这个产生的随机数就相同
        // int a=rand()%10+1;
        // cout<<a<<endl;

        //以上的写法麻烦，且只能产生整数
        //c++的随机库函数 random
        
        //产生均匀分布的整数
        // default_random_engine h;//设置默认随机引擎
        // h.seed(time(0));//设置种子

        random_device rd;
        mt19937 h(rd());

        uniform_int_distribution<int> u(-10,10);
        uniform_real_distribution<double> u2(0,5);
        normal_distribution<double> u3(0,1);
        cout<<u(h)<<endl;
        cout<<u2(h)<<endl;
        cout<<u3(h)<<endl;
        return 0;
}