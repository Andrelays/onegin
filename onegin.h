#ifndef ONEGIN_H_INCLUDED
#define ONEGIN_H_INCLUDED

#include<stdio.h>

char *input_data(const char *file_name);
size_t determine_size(FILE *file_pointer);
FILE *check_isopen (const char *file_name);

#endif // ONEGIN_H_INCLUDED