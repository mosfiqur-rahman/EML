#include "common_eml.h"

/*EML Functions*/

void print_eml_version ()
{
    printf("%s\n", EML_VERSION);
}

void print_compiler_version ()
{
    if (C99 == 1)
    {
	printf("%s\n", "C99");
    }
    else if (C94 == 1)
    {
	printf("%s\n", "C94");
    }
    else if (C90 == 1)
    {
	printf("%s\n", "C94");
    }
    else if (C89 == 1)
    {
	printf("%s\n", "C89");
    }
    else
    {
	printf("%s\n", "Unknown Version");
    }
}

/*Char functions*/

unsigned int charlen (char* s)
{
    unsigned int len = 0;
    
    while (*(s+len) != '\0')
    {
	len++;
    }

    return len;
}

void charcopy (char* cpfrom, char* cpto)
{
    while ((*cpto = *cpfrom) != '\0')
    {
		cpto++;
		cpfrom++;
    }
}


void reverse (char* s)
{
    unsigned int len = charlen (s);
    char temp;

    for(int var = 0; var < len / 2; var++)
    {
	temp = *(s+var);
	*(s+var) = *(s+len-1-var);
	*(s+len-1-var) = temp;
    }
}

char* adjust (char* s)
{
    char* c;
    c = (char*) malloc (charlen (s) * sizeof(char));
    charcopy (s, c);
    return c;
}

void print_cint (char* s)
{
    unsigned int len =  charlen (s);
    
    while (len > 0)
    {
	putchar (*(s+len-1));
	len--;
    }
}


char* print_cint_to_str (char* s)
{
    unsigned int len = charlen (s);
    char* c = (char*) malloc (len * sizeof (char));
	while (len > 0)
	{
		*c = *(s+len-1);
		c++;
		len--;
	}
	return c;
}

/*Operations on char int or C-int*/

void addchar1 (char* a, char* sum, char* dig_sum)
{
    *sum = (*a - '0') + (*dig_sum);
    *dig_sum = *sum / 10;
    *sum = (*sum % 10) + '0';
}

void addchar2 (char* a, char* b, char* sum, char* dig_sum)
{
    *sum = (*a - '0') + (*b - '0') + (*dig_sum);
    *dig_sum = *sum / 10;
    *sum = (*sum % 10) + '0';
}

char* max_cint (char* a, char* b)
{
    unsigned int len_a = charlen (a);
    unsigned int len_b = charlen (b);

    if (len_a > len_b)
    {
	return a;
    }
    else if (len_a < len_b)
    {
	return b;
    }
    else if (*(a+len_a-1) > *(b+len_b-1))
    {
	return a;
    }
    else
    {
	return b;
    }
}

char* min_cint (char* a, char* b)
{
    unsigned int len_a = charlen (a);
    unsigned int len_b = charlen (b);

    if (len_a < len_b)
    {
	return a;
    }
    else if (len_a > len_b)
    {
	return b;
    }
    else if (*(a+len_a-1) < *(b+len_b-1))
    {
	return a;
    }
    else
    {
	return b;
    }
}

char* add_cint (char* a, char* b)
{
    unsigned int len_a = charlen (a);
    unsigned int len_b = charlen (b);

    unsigned int min_len = min (len_a, len_b);
    unsigned int max_len = max (len_a, len_b);

    unsigned int sum_len = max_len + 1;

    char* sum = (char*) malloc (sum_len * sizeof (char));
    
    char* digit_sum = (char*) malloc (sizeof (char));
    *digit_sum = 0;

    a += len_a-1;
    b += len_b-1;
    
    while (min_len > 0)
    {
	addchar2 (a--, b--, sum++, digit_sum);
	min_len--;
    }

    sum_len -= 1;
    
    if (len_a >= len_b)
    {
	while (sum_len > len_b)
	{
	    addchar1 (a--, sum++, digit_sum);
	    sum_len--;
	}
    }
    else
    {
	while (sum_len > len_a)
	{
	    addchar1 (b--, sum++, digit_sum);
	    sum_len--;
	}
    }

    if (*digit_sum > 0)
    {
	*sum = *digit_sum + '0';
	sum++;
	*sum = '\0';

	return (sum-max_len-1);
	
    }

    *sum = '\0';

    return adjust(sum-max_len);
}
