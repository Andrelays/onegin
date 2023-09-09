#include"onegin.h"
#include<stdlib.h>

int main(void)
{
    const char *file_name_test = "test.txt";

    char *buffer = input_data(file_name_test);

    free(buffer);

    return 0;    
}