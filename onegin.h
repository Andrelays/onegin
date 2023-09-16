#ifndef ONEGIN_H_INCLUDED
#define ONEGIN_H_INCLUDED

#include<stdio.h>

struct text_parametrs {
    const char **string_array;
    char        *buffer;
    size_t      *size_string;
    size_t      number_lines;
};

void structor(struct text_parametrs *text, const char *file_name);

char *input_data(const char *file_name);
size_t determine_size(FILE *file_pointer);

void search_strings(struct text_parametrs *text);
size_t count_strings(const char *buffer);

FILE *check_isopen (const char *file_name, const char *opening_mode);
bool check_isclose (FILE *file_pointer);

void sort(struct text_parametrs *text, int (* function_pointer) (const char *, const char *, size_t, size_t));
size_t find_min(const char *const *string_array, const size_t number_lines, size_t *size_string, 
int (* function_pointer) (const char *, const char *, size_t, size_t));
int compare_line(const void *string_1, const void *string_2);
int reverse_compare_line(const char *string_1, const char *string_2, size_t size_string_1, size_t size_string_2);
void swap_pointer(const char **string_array, size_t index_min, size_t number_pass, size_t *size_string);

void output_data(const struct text_parametrs *text, FILE *file_pointer);
void print_string(const char *string, FILE *file_pointer);

void destructor(struct text_parametrs *text);

void quick_sort( void *array,
                 size_t number_elements,
                 size_t size_elements,
                 int (*compare )(const void *, const void *));

void *partition( void *left_border,
                 void *right_border,
                 void *array,
                 size_t number_elements,
                 size_t size_elements,
                 int (*compare )(const void *, const void *));

int compare_int (const void *number_1, const void *number_2);
void swap_values(void* value_1, void* value_2, const size_t size_elements);
void *find_min_pointer(void *pointer_1, void *pointer_2);

#endif // ONEGIN_H_INCLUDED