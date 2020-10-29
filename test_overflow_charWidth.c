/*
 * Overflow char width
 */

#include <stdio.h>

int main()
{
    int x = 128;
    char c = 128, d = 127;
    void *p;
    p = &x;
    printf(" %d %d %d\n", *((char *)p), c, d);
    return 0;
}
