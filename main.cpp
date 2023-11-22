#include<stdlib.h>
#include"onegin.h"
#include"test.h"
#include"libraries/utilities/utilities.h"
#include"libraries/utilities/myassert.h"

int main(int argc, const char *argv[])
{
    const int CORRECT_NUMBER_ARGC = 3;

    if(!check_argc(argc, CORRECT_NUMBER_ARGC)) {
        return INCORRECT_NUMBER_OF_ARGC;
    }

    const char *file_name_input  = argv[1];
    const char *file_name_output = argv[2];

    struct text_parametrs Eugene_Onegin = {};

    FILE *file_pointer_input = check_isopen(file_name_input, "rb");

    text_parametrs_constructor(&Eugene_Onegin, file_pointer_input);

    char *string = ((Eugene_Onegin.string_array)[1]).string_pointer;


    FILE *file_pointer = check_isopen(file_name_output, "wb");

    fprintf(file_pointer, "%s\n\n", Eugene_Onegin.buffer);

    // quick_sort(Eugene_Onegin.string_array, Eugene_Onegin.number_lines, sizeof(string_parametrs), reverse_compare_line);
    // output_data(&Eugene_Onegin, file_pointer);

    quick_sort(Eugene_Onegin.string_array, Eugene_Onegin.number_lines, sizeof(string_parametrs), compare_line);
    output_data(&Eugene_Onegin, file_pointer);

    MYASSERT(check_isclose(file_pointer),  COULD_NOT_CLOSE_THE_FILE, return COULD_NOT_CLOSE_THE_FILE);

    text_parametrs_destructor(&Eugene_Onegin);

    return 0;
}
