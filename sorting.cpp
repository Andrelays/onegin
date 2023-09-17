#include"onegin.h"
#include"myassert.h"
#include"test.h"
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int compare_line(const void *string_parametrs_1, const void *string_parametrs_2)
{
    MYASSERT(string_parametrs_1 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_parametrs_2 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_parametrs_1 != string_parametrs_2, EQUAL_POINTERS_PASSED_TO_FUNC, return 0);

    const char *char_string_1 = ((const string_parametrs *) string_parametrs_1)->string_pointer;
    const char *char_string_2 = ((const string_parametrs *) string_parametrs_2)->string_pointer;                                                    

    while(*char_string_1 != '\n' && *char_string_2 != '\n' && 
          *char_string_1 != '\0' && *char_string_2 != '\0')
    {  
        char_string_1 = move_to_alpha(char_string_1);
        char_string_2 = move_to_alpha(char_string_2);

        if(*char_string_1 == '\n' || *char_string_1 == '\0' || *char_string_2 == '\n' || *char_string_2 == '\0')
            break;

        if(tolower(*char_string_1) != tolower(*char_string_2))
            return (tolower(*char_string_1) - tolower(*char_string_2));

        ++char_string_1;
        ++char_string_2;
    }

    if(*char_string_2 != '\n' && *char_string_2 != '\0')//do -
        return -1;
    
    if(*char_string_1 != '\n' && *char_string_1 != '\0')
        return 1;

    return 0;
}

int reverse_compare_line(const void *string_parametrs_1, const void *string_parametrs_2)
{
    MYASSERT(string_parametrs_1 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_parametrs_2 != NULL,     NULL_POINTER_PASSED_TO_FUNC,   return 0);
    MYASSERT(string_parametrs_1 != string_parametrs_2, EQUAL_POINTERS_PASSED_TO_FUNC, return 0);

    const char *string_1 = ((const string_parametrs *) string_parametrs_1)->string_pointer;
    const char *string_2 = ((const string_parametrs *) string_parametrs_2)->string_pointer;

    size_t size_string_1 = ((const string_parametrs *) string_parametrs_1)->size_string;
    size_t size_string_2 = ((const string_parametrs *) string_parametrs_2)->size_string;

    const char *end_string_1 = string_1 + size_string_1 - 1;
    const char *end_string_2 = string_2 + size_string_2 - 1;

    while(true)
    {  
        end_string_1 = back_to_alpha(string_1, end_string_1);
        end_string_2 = back_to_alpha(string_2, end_string_2);

        if(end_string_1 <= string_1 && end_string_2 <= string_2)                                     
            break;

        if(tolower(*end_string_1) != tolower(*end_string_2))
            return (tolower(*end_string_1) - tolower(*end_string_2));

        --end_string_1;
        --end_string_2;
    }

    if(end_string_1 > string_1 || !isalpha(*end_string_2))
        return 1;
    
    if(end_string_2 > string_2 || !isalpha(*end_string_1))
        return -1;

    return 0;
}

void quick_sort( void *array,
                 size_t number_elements,
                 size_t size_elements,
                 compare_func comparator)
{
    MYASSERT(array      != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(comparator != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    void *left_border  = array;
    void *right_border = (char *) array + size_elements * (number_elements - 1);

    quick_sort_loop(left_border, right_border, size_elements, comparator);
}

void quick_sort_loop( void *left_border,
                 void *right_border,
                 size_t size_elements,
                 compare_func comparator)
{
    MYASSERT(left_border  != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(right_border != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(comparator   != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    if((char *)left_border + 2 * size_elements < right_border)
    {
        void *new_left_border = partition(left_border, right_border, size_elements, comparator);

        quick_sort_loop(left_border, (char *)new_left_border - size_elements, size_elements, comparator);
        quick_sort_loop(new_left_border, right_border,size_elements, comparator);
    }

    if((char *)left_border + size_elements == (char *)right_border && comparator(left_border, right_border) > 0)
        swap_values(left_border, right_border, size_elements);

    if((char *)left_border + 2 * size_elements == (char *)right_border)
        sort_three_values(left_border, right_border, size_elements, comparator); 
}

void *partition( void *left_border,
                 void *right_border,
                 size_t size_elements,
                 compare_func comparator)
{
    MYASSERT(left_border  != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(right_border != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(comparator   != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    void *pivot = calloc(1, size_elements);
    MYASSERT(pivot != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t number_elements = ((char *)right_border - (char *)left_border) / size_elements + 1; 
    void *pointer_pivot = (char *) left_border + size_elements * (number_elements / 2);    

    memcpy(pivot, pointer_pivot, size_elements); 

    bool right_border_not_moved = true;

    while(left_border <= right_border)
    {
        while(comparator(left_border, pivot) < 0)
            left_border = (char*)left_border + size_elements;
    
        while(comparator(right_border, pivot) > 0)
        {
            right_border_not_moved = false;
            right_border = (char*)right_border - size_elements;
        }

        if (left_border <= right_border)
        {
            if (left_border != right_border)
                right_border_not_moved = false;

            swap_values(left_border, right_border, size_elements);
            
            left_border = (char*)left_border + size_elements;
            right_border = (char*)right_border - size_elements;
        }
                
    }
    if(right_border_not_moved)
        left_border = (char *)left_border - size_elements;

    return left_border;
}

int compare_int (const void *number_1, const void *number_2)
{
    MYASSERT(number_1 != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);
    MYASSERT(number_2 != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

    return (*((const int *) number_1) - *((const int *) number_2));
}

void swap_values(void* value_1, void* value_2, const size_t size_elements)
{
    MYASSERT(value_1 != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(value_2 != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
 
    for (size_t index = 0; index < size_elements; index++)
    {
        char temp           = *((char *) value_1 + index);
        *(((char *) value_1) + index) = *(((char *) value_2) + index);
        *(((char *) value_2) + index) = temp;
    }   
}

void sort_three_values(void* left_border, 
                  void* right_border, 
                  size_t size_elements, 
                  compare_func comparator)
{
    MYASSERT(left_border  != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(right_border != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(comparator   != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    if(comparator(left_border, (char *) left_border + size_elements) > 0)
        swap_values(left_border, (char *) left_border + size_elements, size_elements);

    if(comparator((char *) left_border + size_elements, right_border) > 0)
        swap_values((char *) left_border + size_elements, right_border, size_elements);

    if(comparator(left_border, right_border) > 0)
        swap_values(left_border, right_border, size_elements);
} 

const char *move_to_alpha(const char *string)
{
    while(!isalpha(*string) && *string != '\n' && *string != '\0')    
        ++string;

    return string;
}

const char *back_to_alpha(const char *string, const char *end_string)
{
    while(!isalpha(*end_string) && end_string > string)          
            --end_string;

    return end_string;
}