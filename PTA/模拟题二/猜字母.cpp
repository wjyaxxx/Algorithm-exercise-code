#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    n--;
    printf("%c%c",n+'A',n+'a');
    return 0;
}