/******************************************************************************
Rajkumar Radhamanalan

Sample utility code for circular buffer
*******************************************************************************/

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 6
typedef struct circBuff {
    unsigned int data[MAX];
    unsigned int write_index, read_index;
    unsigned short size, length;
}CircularBuffer;

CircularBuffer cbuf;

void init_buffer()
{
    cbuf.write_index = cbuf.read_index = 0;
    cbuf.size = MAX;
    cbuf.length = 0;
}
int read()
{
    int ret_data = 0;
    if (cbuf.length == 0) {
        printf("Buffer is empty\n");
        return 0;
    }
    
    ret_data = cbuf.data[cbuf.read_index];
    if (cbuf.read_index == cbuf.size) {
        cbuf.read_index = 0;
    } else {
        cbuf.read_index++;
    }
    
    cbuf.length--;
    return ret_data;
}

int write(int element)
{
    if ( (cbuf.length == cbuf.size)) {
        printf("Buffer is FULL\n");
        return 0;
    }
    
    printf("data[%d]=%d, element %d\n", cbuf.write_index, cbuf.data[cbuf.write_index], element);
    cbuf.data[cbuf.write_index] = element;
    printf("data[%d]=%d\n", cbuf.write_index, cbuf.data[cbuf.write_index]);
    if (cbuf.write_index == cbuf.size) {
        cbuf.write_index = 0;
    } else {
        cbuf.write_index++;
    }
    cbuf.length++;

    return 1;
}

void print_buffer_stats()
{
    printf("write_index %d, read_index %d, size %d, length %d\n", cbuf.write_index, cbuf.read_index, cbuf.size, cbuf.length);
}

void print_element()
{
    int element=0;
    if (element=read())
        printf("Read element is %d\n", element);
}

int main()
{
    init_buffer();
    write(11);
    write(12);
    write(13);
    write(15);
    write(22);
    print_buffer_stats();
    write(21);
    print_buffer_stats();
    print_element();
    print_element();
    print_element();
    print_element();
    print_buffer_stats();
    write(24);
    print_buffer_stats();
    write(20);
    print_buffer_stats();
    print_element();
    print_element();
    print_element();
    print_element();
    return 0;
}

