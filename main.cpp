#include"onegin.h"
#include"test.h"
#include<stdlib.h>

int main(void)
{
    const char *file_name_test = "test.txt";

    char *buffer = input_data(file_name_test);

    size_t number_lines = 0;

    const char **string_array = search_strings(buffer, &number_lines);

    // char *min_string = find_min(string_array, number_lines);

    // print_string(min_string);

    free(buffer);

    return 0;    
}