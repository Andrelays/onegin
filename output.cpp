#include "onegin.h"
#include "myassert.h"

void output_data(const struct text_parametrs *text, FILE *file_pointer)
{
    MYASSERT(text->string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(file_pointer       != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    size_t index = 0;

    while (index < text->number_lines)
    {
        print_string((text->string_array)[index], file_pointer);
        ++index;
    }

    putc('\n', file_pointer);  
}

void print_string(const char *string, FILE *file_pointer)
{
    MYASSERT(file_pointer != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(string       != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

        bool is_empty_string = true;

    while (*string != '\n' && *string != '\0' && *string != '\r')
    {
        is_empty_string = false;

        putc(*string, file_pointer);

        ++string;
    }
    if (!is_empty_string)
        putc('\n', file_pointer);
}