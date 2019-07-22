#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char* line = malloc(sizeof(char)*50);
   //char* line_copy = malloc(sizeof(char)*50);
   //char* line_token = malloc(sizeof(char)*50);
   int len;

   fgets(line, 50, stdin);
   printf("line is: %s", line);
   strtok(line, "\n");
   len = strlen(line);
   printf("len of line is: %d\n", len);
   printf("%d\n", !strcmp(line, "1"));
   return 0;
}
