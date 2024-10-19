#include <stdio.h>

int main() {

    char  x,y;
    scanf("%c%c", &x, &y);
    unsigned int a=x,b=y;
    printf("%02x%02x",a,b);
    return 0;
}