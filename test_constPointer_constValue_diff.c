#include <stdio.h>

int main()
{
    char buf[] = "comcast";
    char *const p = NULL;
    p = buf;
    printf(" Out: %s\n", p);
    return 0;
}
