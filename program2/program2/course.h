/* Spencer Lawry
 * course header file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   char course_num[10];
   char title[50];
   char days[10];
   char time[10];
   int avail;
} course;

course* make_empty_course();
