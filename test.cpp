#include"test.h"

void print_buffer(char *buffer, size_t size_file)
{
    for(size_t index = 0; index < size_file + 1; index++)
    {
        if(buffer[index] == '\n' )
            printf("buffer[%u] = %d = \'\\n\'\n", index, buffer[index]);

        else if(buffer[index] == '\r')
            printf("buffer[%u] = %d = \'\\r\'\n", index, buffer[index]);
            
        else 
            printf("buffer[%u] = %d = \'%c\'\n", index, buffer[index], buffer[index]);
    }
}