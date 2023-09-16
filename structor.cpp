#include"onegin.h"
#include"myassert.h"
#include"test.h"
#include<stdlib.h>
#include<string.h>

void structor(struct text_parametrs *text, const char *file_name)
{
    MYASSERT(text != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    text->buffer = input_data(file_name);

    search_strings(text);    
}

char *input_data(const char *file_name)
{
    FILE *file_pointer = check_isopen (file_name, "rb");

    if (!file_pointer)
        return NULL;

    size_t size_file = determine_size(file_pointer);

    char *buffer = (char *)calloc(size_file + 1, sizeof(char));
    MYASSERT(buffer != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    fread(buffer, sizeof(char), size_file, file_pointer);

    *(buffer + size_file) = '\0';

    if(!check_isclose (file_pointer))
        return NULL;

    return buffer;
}

size_t determine_size(FILE *file_pointer)
{
    MYASSERT(file_pointer != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

    fseek(file_pointer, 0, SEEK_END);
    long size = ftell(file_pointer);

    MYASSERT(size >= 0, NEGATIVE_VALUE_SIZE_T, return 0);

    rewind(file_pointer);

    return (size_t) size;
}

void search_strings(struct text_parametrs *text)
{
    MYASSERT(text         != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(text->buffer != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    text->number_lines = count_strings(text->buffer);

    text->string_array = (const char **) calloc(text->number_lines, sizeof(char *));
    text->size_string  = (size_t *)      calloc(text->number_lines, sizeof(size_t));

    MYASSERT(text->string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(text->size_string  != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    size_t index = 0;
    const char *string_pointer = text->buffer;

    while(index < text->number_lines)
    {
        *(text->string_array + index) = string_pointer;

        if(index < text->number_lines - 1)
        {
            string_pointer = strchr(string_pointer, '\n') + 1;
            *(text->size_string + index) = string_pointer - *(text->string_array + index);
        }

        else
             *(text->size_string + index) = strchr(string_pointer, '\0') - *(text->string_array + index) + 1;  

        ++index;
    } 
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

FILE *check_isopen (const char *file_name, const char *opening_mode)
{
    MYASSERT(file_name != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    FILE *file_pointer = NULL;

    if ((file_pointer = fopen (file_name, opening_mode)) == NULL || ferror (file_pointer))
        printf("ERROR! Could not open the file \"%s\"!\n", file_name);

    return file_pointer;
}

bool check_isclose (FILE *file_pointer)
{
    if(fclose(file_pointer) != 0)
    {
        printf("ERROR! Could not close the file\n");
        return false;
    }   
    return true;
}