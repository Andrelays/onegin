#include"onegin.h"
#include"test.h"
#include<stdlib.h>

int main(int argc, char *argv[])
{
    // if (argc != 3)
    // {
    //     printf("ERROR! Incorrect numbers of coomand line arguments: %d.\n", argc);

    //     return -1;
    // }
    // const char *file_name_input  = argv[1];
    // const char *file_name_output = argv[2];

    // struct text_parametrs Eugene_Onegin = {
    //     .string_array = NULL,
    //     .buffer       = NULL,
    //     .size_string  = NULL,
    //     .number_lines = 0
    // };

    // structor(&Eugene_Onegin, file_name_input);

    // FILE *file_pointer = check_isopen (file_name_output, "wb");

    // fprintf(file_pointer, "%s", Eugene_Onegin.buffer);
    // putc('\n', file_pointer);

    // sort(&Eugene_Onegin, reverse_compare_line);

    // output_data(&Eugene_Onegin, file_pointer);

    // sort(&Eugene_Onegin, compare_line);

    // output_data(&Eugene_Onegin, file_pointer);

    // // for (size_t i = 0; i < Eugene_Onegin.number_lines; i++)
    // //     printf("%u\n", Eugene_Onegin.size_string[i]);

    // if(!check_isclose (file_pointer))
    //     return -2;

    // destructor(&Eugene_Onegin);

    const size_t size_array = 3;

    int array[size_array] = {3, 2, 1};

    //printf("%d", ((int*) partition(array, array + size_array - 1, array, size_array, sizeof(int), compare_int))[0]);
    quick_sort(array, size_array, sizeof(int), compare_int);

    for(size_t i = 0; i < size_array; i++)
    {
        printf("\n%d", array[i]);
    }

    return 0;    
}