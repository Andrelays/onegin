#include"onegin.h"
#include"myassert.h"
#include<ctype.h>

// void sort(const char **string_array, const size_t number_lines)
// {
//     MYASSERT(string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

//     for (size_t number_pass = 0; number_pass < number_lines - 1; number_pass++)
//     {
//         find_min(string_array + number_pass, number_lines - number_pass);
//         swap_pointer();
//     }
// }

// char *find_min(const char *const *string_array, const size_t number_lines)
// {
//     char *pointer_minimum = (char*) *string_array;

//     for(size_t index = 1; index < number_lines - 1 ; index++)
//         if(compare_line(pointer_minimum, *(string_array + index)) > 0)
//             pointer_minimum = (char*) *(string_array + index);

//     return pointer_minimum;
// }

int compare_line(const char *string_1, const char *string_2)
{
    MYASSERT(string_1 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_2 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_1 != string_2, EQUAL_POINTERS_PASSED_TO_FUNC, return 0);

    #define MOVE_TO_ALPHA(string)                                               \
        while(!isalpha(*string_1) && *string_1 != '\n' && *string_1 != '\0')    \
            ++string_1;                                                         \
                                                                                \
        if(*string_1 == '\n' || *string_1 == '\0')                              \
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