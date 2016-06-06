#ifndef _ARBITRARY_LARGE_
#    define _ARBITRARY_LARGE_
#    include "common_eml.h"

    /* Fixed Width Integer Definition For PRE C99*/
#    if !defined (PREDEF_STANDARD_C_1999)
#    define uint8_t unsigned short int
#    define uint16_t unsigned short int
#    define uint32_t unsigned long int
#    define uint64_t unsigned long int

#    define int8_t short int
#    define int16_t short int
#    define int32_t long int
#    define int64_t long int

    /* Struct Defs of Arbritrary Large Int*/
    struct ual8
	{
		uint8_t val;
		uint8_t* next;
	};

    struct ual16
	{
		uint16_t val;
		uint16_t* next;
	};

    struct ual32
	{
		uint32_t val;
		uint32_t* next;
	};

    struct ual64
	{
		uint64_t val;
		uint64_t* next;
	};

    struct al8
	{
		int8_t val;
		int8_t* next;
	};

    struct al16
	{
		int16_t val;
	        int16_t* next;
	};

    struct al32
	{
		int32_t val;
		int32_t* next;
	};

    struct al64
	{
		int64_t val;
		int64_t* next;
	};

    /* Type Def of Arbitrary Large Ints*/

#    define ual8_t struct ual8
#    define ual16_t struct ual16
#    define ual32_t struct ual32
#    define ual64_t struct ual64
#    define al8_t struct al8
#    define al16_t struct al16
#    define al32_t struct al32
#    define al64_t struct al64

    /* Data Init Functions Protypes */

    void data_init (ual8_t* num, char* s);
    void data_init (ual16_t* num, char* s);
    void data_init (ual32_t* num, char* s);
    void data_init (ual64_t* num, char* s);
    void data_init (al8_t* num, char* s);
    void data_init (al16_t* num, char* s);
    void data_init (al32_t* num, char* s);
    void data_init (al64_t* num, char* s);


#endif
