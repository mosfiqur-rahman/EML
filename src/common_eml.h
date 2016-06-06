#ifndef _EML_COMMOM_
#    define _EML_COMMOM_
#    define EML_VERSION "0.1"

#    include <stdio.h>
#    include <string.h>
#    include <stddef.h>
#    include <stdlib.h>

    /*Defining Compiler Standards*/
#    define C89 0
#    define C90 0
#    define C94 0
#    define C99 0

    /*Checking Compiler Standards*/
#    if defined (__STDC__)
#        define PREDEF_STANDARD_C_1989
#        undef C89
#        define C89 1
#        if defined (__STDC_VERSION__)
#            define PREDEF_STANDARD_C_1990
#            undef C90
#            define C90 1
#            if (__STDC_VERSION__ >= 199409L)
#                define PREDEF_STANDARD_C_1994
#                undef C94
#                define C94 1
#            endif
#            if (__STDC_VERSION__ >= 199901L)
#                define PREDEF_STANDARD_C_1999
#                undef C99
#                define C99 1
#            endif
#        endif
#    endif

    /*Defining bool Type*/
#    if defined (PREDEF_STANDARD_C_1999) && defined (_Bool)
#         #define bool _Bool
#    else
#        define TRUE 1
#        define FALSE 0
#        define bool short int
#    endif

    /*Common Defs*/

#     define max(a,b)                           \
             ({                                 \
		 __typeof__ (a) _a = (a);	\
                 __typeof__ (b) _b = (b);       \
                 _a > _b ? _a : _b;             \
	     })


#     define min(a,b)                           \
             ({                                 \
		 __typeof__ (a) _a = (a);	\
                 __typeof__ (b) _b = (b);       \
                 _a < _b ? _a : _b;             \
	     })

#    define NULL_CHAR 0

/*Function Prototypes*/

/*EML Functions*/
void print_eml_version ();
void print_compiler_version ();

/*Char functions*/
unsigned int charlen (char* s);
void charcopy (char* cpfrom, char* cpto);
void reverse (char* s);
char* adjust (char* s);
void print_cint (char* s);
char* print_cint_to_str (char* s);

/*Operations on char int or C-int*/
void addchar1 (char* a, char* sum, char* dig_sum);
void addchar2 (char* a, char* b, char* sum, char* dig_sum);
char* max_cint (char* a, char* b);
char* min_cint (char* a, char* b);
char* add_cint (char* a, char* b);
#endif
