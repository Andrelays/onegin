#include"onegin.h"
#include"myassert.h"
#include"test.h"
#include<stdlib.h>

char *input_data(const char *file_name)
{
    FILE *file_pointer = check_isopen (file_name);
    size_t size_file = determine_size(file_pointer);

    char *buffer = (char *)calloc(size_file + 1, sizeof(char));
    fread(buffer, sizeof(char), size_file, file_pointer);

    *(buffer + size_file + 1) = '\0';

    #ifdef TEST
        printf("size_file = %u\n\n", size_file);
        printf("buffer = %p\n\n", buffer);
        print_buffer(buffer, size_file);
        
    #endif
    printf("1");
    if(fclose(file_pointer) != 0)
    {
        printf("ERROR. FAILED TO CLOSE FILE");

        return NULL;
    }
    printf("1");
 
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

FILE *check_isopen (const char *file_name)
{
    MYASSERT(file_name != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    FILE *file_pointer = NULL;

    if ((file_pointer = fopen (file_name, "rb")) == NULL || ferror (file_pointer)) // todo func, check isopen-
        printf("MISTAKE! Could not open the file \"%s\"!\n", file_name);

    return file_pointer;
}