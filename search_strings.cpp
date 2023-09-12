#include"onegin.h"
#include"myassert.h"
#include"test.h"
#include<stdlib.h>
#include<string.h>

const char **search_strings(const char *buffer, size_t *number_lines)
{
    MYASSERT(buffer       != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(number_lines != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    *number_lines = count_strings(buffer);
    const char **string_array = (const char **) calloc(*number_lines, sizeof(char *));

    size_t index = 0;
    char *string_pointer = (char*) buffer;
    while(index < *number_lines)
    {
        *(string_array + index) = string_pointer;
        string_pointer = strchr(string_pointer, '\n') + 1;

        print_string(*(string_array + index));

        ++index;
    }

    return string_array; 
}

size_t count_strings(const char *buffer)
{
    MYASSERT(buffer != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

    size_t count = 0;

    for (size_t index = 0; buffer[index] != '\0'; index++)
        if (buffer[index] == '\n')
            count++;
    
    return (count + 1);
}