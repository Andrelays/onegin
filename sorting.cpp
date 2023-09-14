#include"onegin.h"
#include"myassert.h"
#include"test.h"
#include<ctype.h>

void sort(void *array, const size_t size, , int (* function_pointer) (const char *, const char *, size_t, size_t))
{
    MYASSERT(text->string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    for (size_t number_pass = 0; number_pass < text->number_lines - 1; number_pass++)
    {
        MYASSERT(number_pass < text->number_lines, GOING_BEYOUND_BOUNDARY_ARRAY, return);

        size_t index_min = find_min(text->string_array + number_pass, 
                                    text->number_lines - number_pass, 
                                    text->size_string  + number_pass, function_pointer) + number_pass;

        swap_pointer(text->string_array, index_min, number_pass, text->size_string);
    }
}

size_t find_min(const char *const *string_array, const size_t number_lines, size_t *size_string, 
                int (* function_pointer) (const char *, const char *, size_t, size_t))
{
    MYASSERT(string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

    const char *pointer_minimum = *string_array;
    size_t index_min = 0;

    for(size_t index = 1; index < number_lines; index++)
    {
        MYASSERT(index < number_lines, GOING_BEYOUND_BOUNDARY_ARRAY, return 0);
        //printf("function_pointer = %d\n", function_pointer(pointer_minimum, string_array[index], size_string[index_min], size_string[index]));

        if(function_pointer(pointer_minimum, string_array[index], size_string[index_min], size_string[index]) > 0)
        {
            pointer_minimum = string_array[index];
            index_min = index;
        }
    }
    return index_min;
}

int compare_line(const char *string_1, const char *string_2, size_t size_string_1, size_t size_string_2)
{
    MYASSERT(string_1 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_2 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_1 != string_2, EQUAL_POINTERS_PASSED_TO_FUNC, return 0);

    #define MOVE_TO_ALPHA(string)                                               \
        while(!isalpha(*string) && *string != '\n' && *string != '\0')          \
            ++string;                                                           \
                                                                                \
        if(*string == '\n' || *string == '\0')                                  \
            break

    while(*string_1 != '\n' && *string_2 != '\n' && 
          *string_1 != '\0' && *string_2 != '\0')
    {  
        MOVE_TO_ALPHA(string_1);
        MOVE_TO_ALPHA(string_2);

        if(tolower(*string_1) != tolower(*string_2))
            return (tolower(*string_1) - tolower(*string_2));

        ++string_1;
        ++string_2;
    }

    #undef MOVE_TO_ALPHA

    if(*string_2 != '\n' && *string_2 != '\0')
        return -1;
    
    if(*string_1 != '\n' && *string_1 != '\0')
        return 1;

    return 0;
}

int reverse_compare_line(const char *string_1, const char *string_2, size_t size_string_1, size_t size_string_2)
{
    MYASSERT(string_1 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_2 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_1 != string_2, EQUAL_POINTERS_PASSED_TO_FUNC, return 0);

    const char *end_string_1 = string_1 + size_string_1 - 1;
    const char *end_string_2 = string_2 + size_string_2 - 1;
    // printf("string_1 = %p end_string_1 = %p size_string_1 = %u\n",string_1, end_string_1, size_string_1);
    // print_string(string_1);
    // printf("string_2 = %p end_string_2 = %p size_string_2 = %u\n",string_2, end_string_2, size_string_2);
    // print_string(string_2);

    #define MOVE_TO_ALPHA(string, end_string)                        \
        while(!isalpha(*end_string) && end_string > string)          \
            --end_string;                                            \
                                                                     \
        if(end_string <= string)                                     \
            break

    while(end_string_1 > string_1 && 
          end_string_2 > string_2)
    {  
        MOVE_TO_ALPHA(string_1, end_string_1);
        MOVE_TO_ALPHA(string_2, end_string_2);

        if(tolower(*end_string_1) != tolower(*end_string_2))
            return (tolower(*end_string_1) - tolower(*end_string_2));

        --end_string_1;
        --end_string_2;
    }

    #undef MOVE_TO_ALPHA

    if(end_string_1 > string_1)
        return -1;
    
    if(end_string_2 > string_2)
        return 1;

    return 0;
}

void swap_pointer(const char **string_array, size_t index_min, size_t number_pass, size_t *size_string)
{
    MYASSERT(string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    // printf("\n-------------------------------------------------------\n");
    // printf("*(string_array + number_pass) = %p *(size_string + number_pass) = %u\n",*(string_array + number_pass), *(size_string + number_pass));
    // print_string(*(string_array + number_pass));

    // printf("*(string_array + index_min) = %p *(size_string + index_min) = %u\n",*(string_array + index_min), *(size_string + index_min));
    // print_string(*(string_array + index_min));

    const char *pointer_buffer = *(string_array + number_pass); 

    *(string_array + number_pass) = *(string_array + index_min);
    *(string_array + index_min) = pointer_buffer;

    size_t size_buffer = *(size_string + number_pass); 


    *(size_string + number_pass) = *(size_string + index_min);
    *(size_string + index_min) = size_buffer;

    // printf("\n\n*(string_array + number_pass) = %p *(size_string + number_pass) = %u\n",*(string_array + number_pass), *(size_string + number_pass));
    // print_string(*(string_array + number_pass));

    // printf("*(string_array + index_min) = %p *(size_string + index_min) = %u\n",*(string_array + index_min), *(size_string + index_min));
    // print_string(*(string_array + index_min));
    // printf("\n-------------------------------------------------------\n");
}