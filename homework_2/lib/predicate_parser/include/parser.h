#ifndef __PARSER_H__
#define __PARSER_H__


#include "my_string.h"
#include "operators.h"

#define MAX_BRACKETS 100

typedef enum
{
    OK = 0,
    WAIT = 1,
    INVALID_SYNTAX = -1,
    ALLOCATE_ERROR = -2
} error_code;


typedef struct
{
	 cmp_opr *compare; // 8
	 int *numbers;     // 8
	 logic_opr *logic; // 8
	 int count_cmp;    // 4
} predicate;           // 32

error_code allocate_predicate(predicate *pred, int count_cmp);
void free_predicate(predicate **pred);

error_code parse_predicate(my_string str_pred, predicate *pred);
bool do_predicate(predicate *pred, int number);


#endif