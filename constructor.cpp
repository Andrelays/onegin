#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"onegin.h"
#include"libraries/utilities/myassert.h"
#include"test.h"

void text_parametrs_constructor(struct text_parametrs *text, FILE *file_pointer)
{
    MYASSERT(text != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    text->buffer = input_data(file_pointer);

    search_strings(text);
}

char *input_data(FILE *file_pointer)
{
    size_t size_file = determine_size(file_pointer);

    char *buffer = (char *)calloc(size_file + 1, sizeof(char));
    MYASSERT(buffer != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_file = fread(buffer, sizeof(char), size_file, file_pointer);

    buffer[size_file] = '\0';

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

    text->string_array = (string_parametrs *) calloc(text->number_lines, sizeof(string_parametrs));

    MYASSERT(text->string_array != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    size_t index = 0;
    char *string_pointer = text->buffer;

    for (index = 0; index < text->number_lines - 1; index++)
    {
        ((text->string_array)[index]).string_pointer = string_pointer;

        string_pointer = strchr(string_pointer, '\n') + 1;

        ((text->string_array)[index]).size_string = string_pointer - ((text->string_array)[index]).string_pointer;
    }

    ((text->string_array)[index]).string_pointer = string_pointer;

    ((text->string_array)[index]).size_string = strchr(string_pointer, '\0') - ((text->string_array)[index]).string_pointer + 1;
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

const char *skip_spaces(const char *string)
{
    MYASSERT(string != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t string_index = 0;

    for(string_index = 0; string[string_index] != '\0'; string_index++)
    {
        if (!isspace(string[string_index]) && string[string_index] != '\0') {
            break;
        }
    }

    return string + string_index;
}

errors_code replace_chars_to_null_character(char *text, const char *replaceable_characters)
{
    MYASSERT(text                   != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL_POINTER_PASSED_TO_FUNC);
    MYASSERT(replaceable_characters != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL_POINTER_PASSED_TO_FUNC);

    text = strpbrk(text, replaceable_characters);

    while (*text != NULL)
    {
        *text  = '\0';
         text  = strpbrk(text, replaceable_characters);
    }

    return ASSERT_NO_ERROR;
}
