#include <stdio.h>
int main()
{
    int n;
    scanf("%x",&n);
    
    int pre=n/256,suf=n%256;
    printf("%c%c",pre,suf);
    return 0;
}