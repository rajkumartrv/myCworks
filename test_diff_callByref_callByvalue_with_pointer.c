/*
 * Commented are working code, reason explained below
 *
 * This is because func() makes a copy of the pointer, so when malloc() is called,
 *  it is setting the copied pointer to the memory location, not p. p is pointing
 *  to random memory before and after the call to fun(), and when you dereference it, it will crash.
 *
 * If you want to add memory to a pointer from a function, you need to pass the address of 
 *  the pointer (ie. double pointer).
 */

#include <stdio.h>
#include <stdlib.h>
//void func(int **a)
void func(int *a)
{
    //*a = (int *)malloc(sizeof(int));
    a = (int *)malloc(sizeof(int));
}

int main()
{
    int *p = NULL;
    //func(&p);
    func(p);
    *p=6;
    printf("p %d\n", *p);

    return 0;
}
