/******************************************************************************
Rajkumar Radhamanalan

Sample utility code for circular buffer
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 7
typedef struct circBuff {
    unsigned int data[MAX];
    unsigned int write_index, read_index;
    int size;
}CircularBuffer;

CircularBuffer cbuf;

//CircularBuffer *cbuf=(CircularBuffer *)malloc(sizeof(CircularBuffer));

int read()
{
    int ret_data = 0;
    if(cbuf.write_index == cbuf.read_index) {
        printf("Buffer is empty\n");
        return 0;
    }
    
    ret_data = cbuf.data[cbuf.read_index];
    if (cbuf.read_index == cbuf.size)
        cbuf.read_index = 0;
    else
        cbuf.read_index++;
        
    return ret_data;
}

int write(int element)
{
    if ((cbuf.write_index + 1) == cbuf.read_index) {
        printf("Buffer is FULL\n");
        return 0;
    }
    
    cbuf.data[cbuf.write_index] = element;
    printf("data[%d] = %d\n", cbuf.write_index, cbuf.data[cbuf.write_index]);
    cbuf.write_index++;
    if (cbuf.write_index == cbuf.size) {
        cbuf.write_index = 0;
    }
    
    return 1;
}

int main()
{
    cbuf.write_index = 0;
    cbuf.read_index = 0;
    cbuf.size = MAX - 1;
    printf("size of cbuf is %d\n", sizeof(cbuf.data)/sizeof(cbuf.data[0]));
    printf("write_index %d, read_index %d, size %d\n", cbuf.write_index, cbuf.read_index, cbuf.size);
    write(11);
    write(12);
    write(13);
    write(15);
    write(22);
    write(21);
    printf("write_index %d, read_index %d\n", cbuf.write_index, cbuf.read_index);
    write(20);
    //write(24);
    printf("Read element is %d\n", read());
    printf("Read element is %d\n", read());
    printf("Read element is %d\n", read());
    printf("Read element is %d\n", read());
    printf("Read element is %d\n", read());
    printf("write_index %d, read_index %d, size %d\n", cbuf.write_index, cbuf.read_index, cbuf.size);
    printf("Read element is %d\n", read());
    printf("write_index %d, read_index %d, size %d\n", cbuf.write_index, cbuf.read_index, cbuf.size);
    printf("Read element is %d\n", read());
    printf("Read element is %d\n", read());
    return 0;
}

