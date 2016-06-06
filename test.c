#include "src/common_eml.h"

int main()
{
    int i;
    
    print_eml_version ();
    print_compiler_version ();

    char a[1000], b[1000], *sum;
    *sum = 1;

    for (i = 0; i < 999; i++)
    {
	*(a + i) = '1';
    }

    *(a + i) = '\0';

    for (i = 0; i < 990; i++)
    {
	*(b + i) = '1';
    }

    *(a + i) = '\0';

    add_char_int (a, b, sum);

    printf ("%s\n", sum);
    
    return 0;
}
