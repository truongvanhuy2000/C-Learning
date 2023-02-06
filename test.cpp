#include <stdio.h>
char mang[] = {0x01, 0x03, 0x20, 0x04, 0x05};
char *pointer = &mang[0];
int *pp = (int *)pointer;
int main()
{
    printf("%d", pp[1]);
    return 0;
}