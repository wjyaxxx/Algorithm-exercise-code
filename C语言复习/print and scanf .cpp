#include <cstdio>
#include <iostream>
int main()
{
    int n;
    scanf("%d",&n);
    switch(n%3)
    {
        case 1:
            std::cout<<"1"<<' '<<n<<std::endl;
        case 2:
            std::cout<<"2"<<' '<<n<<std::endl;
        case 3:
            std::cout<<"3"<<' '<<n<<std::endl;
    }
    return 0;
}
