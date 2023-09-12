#ifndef ONEGIN_H_INCLUDED
#define ONEGIN_H_INCLUDED

#include<stdio.h>

char *input_data(const char *file_name);
size_t determine_size(FILE *file_pointer);
FILE *check_isopen (const char *file_name);
size_t count_strings(const char *buffer);
const char **search_strings(const char *buffer, size_t *number_lines);
char *find_min(const char *const *string_array, const size_t number_lines);
int compare_line(const char *string_1, const char *string_2);

#endif // ONEGIN_H_INCLUDED