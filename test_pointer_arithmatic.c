/*

The idea is that you're pointing to blocks of memory

+----+----+----+----+----+----+
| 06 | 07 | 08 | 09 | 10 | 11 | mem
+----+----+----+----+----+----+
| 18 | 24 | 17 | 53 | -7 | 14 | data
+----+----+----+----+----+----+

If you have int* p = &(array[5]) then *p will be 14. Going p=p-3 would make *p be 17.
So if you have int* p = &(array[5]) and int *q = &(array[3]), then p-q should be 2,
because the pointers are point to memory that are 2 blocks apart.

*/


#include <stdio.h>

int main()
{
    int *p;
    int a[] = {5, 2, 3, 8};
    p = &a[3];
    int *q = &a[2];
    printf("p-q %d\n", (p-q));
    return 0;
}
