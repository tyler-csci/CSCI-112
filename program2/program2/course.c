
#include <stdlib.h>
typedef struct
{
   char class_num[10];
   char title[50];
   char days[10];
   char time[10];
   int avail;
} course;

course* make_empty_course()
{
   course* a = (course*) malloc(sizeof(course));
   return a;
}
