#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
 *                        常量                                            *
 **************************************************************************/

typedef unsigned char BYTE;
typedef unsigned short int WORD;
typedef unsigned long  int DWORD;

/**************************************************************************
 *                          宏定义                                         *
 **************************************************************************/

#define OVERFLOW -1
#define ILLEGAL  -2

#define OK        2
#define ERROR    -4

#define EQUAL     3
#define UNEQUAL  -3

#define TRUE      5
#define FALSE    -5

typedef enum bool
{
    false,
    true
}bool;

#endif// end for _COMMON_H_