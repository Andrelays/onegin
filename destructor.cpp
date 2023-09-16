#include "onegin.h"
#include "myassert.h"
#include <stdlib.h>

void destructor(struct text_parametrs *text)
{
    MYASSERT(text != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    free(text->buffer);
    free(text->string_array);
    for(size_t index = 0; index < text->number_lines; index++)
        (text->size_string)[index] = -1;

    free(text->size_string);

    text->number_lines = -1;
}