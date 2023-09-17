#include"onegin.h"
#include"test.h"
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        printf("ERROR! Incorrect numbers of coomand line arguments: %d.\n", argc);
        return -1;
    }

    const char *file_name_input  = argv[1];
    const char *file_name_output = argv[2];

    struct text_parametrs Eugene_Onegin = {
        .string_array = NULL,
        .buffer       = NULL,
        .number_lines = 0
    };

    constructor(&Eugene_Onegin, file_name_input);

    FILE *file_pointer = check_isopen (file_name_output, "wb");

    fprintf(file_pointer, "%s\n\n", Eugene_Onegin.buffer);

    qsort(Eugene_Onegin.string_array, Eugene_Onegin.number_lines, sizeof(string_parametrs), reverse_compare_line);
    output_data(&Eugene_Onegin, file_pointer);

    quick_sort(Eugene_Onegin.string_array, Eugene_Onegin.number_lines, sizeof(string_parametrs), compare_line);
    output_data(&Eugene_Onegin, file_pointer);

    if(!check_isclose (file_pointer))
        return -2;

    destructor(&Eugene_Onegin);

    return 0;    
}