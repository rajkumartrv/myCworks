/******************************************************************************

Rajkumar Radhamanalan

Circular Sample code
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 6
typedef struct circBuff {
    unsigned int data[MAX]; //biffer
    unsigned int write_index, read_index; //maintain read, write position
    unsigned short size, length; // having size of buffer and remaining elements to read and write
}CircularBuffer;

CircularBuffer cbuf;

//Buffer initialization
void init_buffer()
{
    cbuf.write_index = cbuf.read_index = 0;
    cbuf.size = MAX;
    cbuf.length = 0;
}


int read()
{
    int ret_data = 0;
    //Checking buffer empty case
    if (cbuf.length == 0) {
        printf("Buffer is empty\n");
        return 0;
    }
    
    ret_data = cbuf.data[cbuf.read_index];
    cbuf.read_index++;
    if (cbuf.read_index == cbuf.size) {
        cbuf.read_index = 0;
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
    
    cbuf.data[cbuf.write_index] = element;
    cbuf.write_index++;
    if (cbuf.write_index == cbuf.size) {
        cbuf.write_index = 0;
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
    write(24);
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
    print_buffer_stats();
    return 0;
}

