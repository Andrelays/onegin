#include "onegin.h"
#include "myassert.h"
#include <stdlib.h>

void destructor(struct text_parametrs *text)
{
    MYASSERT(text != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    free(text->buffer);
    free(text->string_array);

    text->number_lines = -1;
}