#include <stdio.h>
int main()
{
    char x;
    long long key;
    scanf("%c%lld",&x,&key);
    key=-key;
    key%=26;
    key+=26;
    key%=26;
    printf("%c",(x-'a'+key)%26+'a');
    return 0;
}