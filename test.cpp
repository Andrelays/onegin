#include"test.h"
#include "colors.h"

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

// void print_partition(const char *left_border, const char *right_border, char *pivot, char *array, size_t number_elements)
// {
//     int *pointer = array; 
//     while(pointer < array + number_elements)
//     {
//         if(pointer < left_border && pointer < right_border)
//             printf(MAGENTA "%d" RESET_COLOR, *pointer);

//         else if(pointer == left_border)
//             printf(BLUE "%d" RESET_COLOR, *pointer);

//         else if(pointer < pivot && pointer < right_border)
//             printf(CYAN "%d" RESET_COLOR, *pointer);

//         else if(pointer == pivot && pointer != right_border)
//             printf(GREEN "%d" RESET_COLOR, *pointer);
        
//         else if(pointer < right_border)
//             printf(YELLOW "%d" RESET_COLOR, *pointer);
        
//         else if(pointer == right_border)
//             printf(RED "%d" RESET_COLOR, *pointer);
        
//         else
//             printf(MAGENTA "%d" RESET_COLOR, *pointer);

//         ++pointer;    
//     }
//     printf("       left = %p   right = %p\n", left_border, right_border);
// }

void print_partition(const int *left_border, const int *right_border, int *pivot, int *array, size_t number_elements)
{
    int *pointer = array; 
    while(pointer < array + number_elements)
    {
        if(pointer < left_border && pointer < right_border)
            printf(MAGENTA "%d" RESET_COLOR, *pointer);

        else if(pointer == left_border)
            printf(BLUE "%d" RESET_COLOR, *pointer);

        else if(pointer < pivot && pointer < right_border)
            printf(CYAN "%d" RESET_COLOR, *pointer);

        else if(pointer == pivot && pointer != right_border)
            printf(GREEN "%d" RESET_COLOR, *pointer);
        
        else if(pointer < right_border)
            printf(YELLOW "%d" RESET_COLOR, *pointer);
        
        else if(pointer == right_border)
            printf(RED "%d" RESET_COLOR, *pointer);
        
        else
            printf(MAGENTA "%d" RESET_COLOR, *pointer);

        ++pointer;    
    }
    printf("       left = %p   right = %p\n", left_border, right_border);
}