#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int pre=n/100,suf=n%100;
    printf("%c%c",pre+160,suf+160);
    return 0;
}