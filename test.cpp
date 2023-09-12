#include"test.h"

void print_buffer(const char *buffer, size_t size_file)
{
    for(size_t index = 0; index < size_file; index++)
    {
        if(buffer[index] == '\n' )
            printf("buffer[%u] = %d = \'\\n\'\n", index, buffer[index]);

        else if(buffer[index] == '\r')
            printf("buffer[%u] = %d = \'\\r\'\n", index, buffer[index]);
            
        else 
            printf("buffer[%u] = %d = \'%c\'\n", index, buffer[index], buffer[index]);
    }
}

void print_string(const char *string)
{
    size_t index = 0;

    printf("string = %p\n", string);

    while(string[index] != '\n' && string[index] != '\0')
    {

        if(string[index] == '\r')
            printf("string[%u] = %3d = \'\\r\'\n", index, string[index]);
            
        else 
            printf("string[%u] = %3d = \'%c\'\n", index, string[index], string[index]);

        ++index;
    }
    if(string[index] == '\n' )
        printf("string[%u] = %3d = \'\\n\'\n", index, string[index]);
        
    else if(string[index] == '\0')
        printf("string[%u] = %3d = \'\\0\'\n", index, string[index]);

    printf("\n");
}