#include <bits/stdc++.h>
using namespace std;
char str1[25],str2[25];
int main()
{
        printf("请输入要转换的美国日期:");
        scanf("%s",str1);
        
        int mon,day,year;//月,日,年
        sscanf(str1,"%d-%d-%d",&mon,&day,&year);//sscanf就是从字符串读入的函数
        printf("你所转换的中国日期如下:");
        printf("%04d-%02d-%02d",year,mon,day);


        return 0;
}