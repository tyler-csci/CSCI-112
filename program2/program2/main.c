

#include "course.h"
#include "linked_list.h"
#include "main.h"
#define LINE_SIZE 100

int main()
{
   FILE* in;
   FILE* out = fopen("print_log.txt", "w");
   char line[LINE_SIZE];
   char temp[50];

   course* c_ptr = make_empty_course(); //points to the current course
   node* first = make_node(c_ptr); //points to the first node (is the linked list)

   in = fopen("classes.txt", "r");
   if (in == NULL)
   {
      perror("Could not find classes.txt file");
      exit(-1);
   }
   while (fgets(line, LINE_SIZE, in) != NULL) //parses the file and creates linked list of courses
   {
      strcpy(c_ptr->course_num, strtok(line, " "));
      strcpy(c_ptr->title, strtok(NULL, ":"));
      c_ptr->title[strlen(c_ptr->title) - 1] = '\0';   // removing pesky space from end of str
      strcpy(c_ptr->days, strtok(NULL, " "));
      strcpy(c_ptr->time, strtok(NULL, " "));
      c_ptr->avail =  atoi(strtok(NULL, " ")); // turns avail from a string into an int
      if (first->cur != c_ptr) // to avoid a duplicate on the first time
      {
         add(first, c_ptr); // adds the course to the linked list
      }
      c_ptr = make_empty_course(); // resets the course* with new course memory allocated
   }
   free(c_ptr);
   run_menu(first, out);
   free(first);
   return 0;
}
void run_menu(node* first, FILE* out)
{
   node* sorted_list;
   char* input = malloc(sizeof(char)*LINE_SIZE);
   char* input_tok = malloc(sizeof(char)*LINE_SIZE);
   input[0] = '\0';

   printf("Welcome to the class sorting menu. Type !quit at any time to exit\n"
         "These are your options:\n"
         "1) Type '1' to print all classes by CSCI number\n"
         "2) Type 'MWF' or 'TR' to print classes available MWF or TR respectively\n"
         "3) Type a specific day/time combination such as 'MWF 0900' or 'TR 1100 to search\n"
         "   and print classes available at that day/time combination\n"
         "4) Type a college year ('freshman', 'sophomore', 'junior' or 'senior' to search\n"
         "   and print classes available to that college year\n");

   fprintf(out, "Welcome to the class sorting menu. Type !quit at any time to exit\n"
         "These are your options:\n"
         "1) Type '1' to print all classes by CSCI number\n"
         "2) Type 'MWF' or 'TR' to print classes available MWF or TR respectively\n"
         "3) Type a specific day/time combination such as 'MWF 0900' or 'TR 1100 to search\n"
         "   and print classes available at that day/time combination\n"
         "4) Type a college year ('freshman', 'sophomore', 'junior' or 'senior' to search\n"
         "   and print classes available to that college year\n");
   do
   {
      printf("\n");
      fprintf(out, "\n");

      fgets(input, LINE_SIZE, stdin);
      input = strtok(input, "\n ");
      input_tok = strtok(NULL, "\n ");

      if (!strcmp(input, "!quit"))
      {
         break;
      }
      else if (!strcmp(input, "1"))
      {
         first = sort_by_thing("num", first, NULL);
         print_stuff(first, out);
      }
      else if (input_tok == NULL && (!strcmp(input, "MWF") || !strcmp(input, "TR")))
      {
         first = sort_by_thing("time", first, NULL);
         sorted_list = list_day_time(input, -1, first, NULL);
         print_stuff(sorted_list, out);
      }
      else if (!strcmp(input, "MWF") || !strcmp(input, "TR"))
      {
         if (input_tok != NULL && atoi(input_tok) != 0) // checks for valid 2nd token
         {
            sorted_list = list_day_time(input, atoi(input_tok), first, NULL);
            print_stuff(sorted_list, out);
         }
         else
         {
            printf("invalid input\n");
            fprintf(out, "invalid input\n");
            break;
         }
      }
      else if (!strcmp(input, "freshman"))
      {
         first = sort_by_thing("num", first, NULL);
         sorted_list = list_by_year(1, first, NULL);
         print_stuff(sorted_list, out);
      }
      else if (!strcmp(input, "sophomore"))
      {
         first = sort_by_thing("num", first, NULL);
         sorted_list = list_by_year(2, first, NULL);
         print_stuff(sorted_list, out);
      }
      else if (!strcmp(input, "junior"))
      {
         first = sort_by_thing("num", first, NULL);
         sorted_list = list_by_year(3, first, NULL);
         print_stuff(sorted_list, out);
      }
      else if (!strcmp(input, "senior"))
      {
         first = sort_by_thing("num", first, NULL);
         sorted_list = list_by_year(4, first, NULL);
         print_stuff(sorted_list, out);
      }
      else
      {
         printf("invalid input\n");
         fprintf(out, "invalid input\n");
         break;
      }
   }while (1);
}
void print_stuff(node* course_list, FILE* out)
{
   char* years[11] = {"Freshmen", "Sophomores", "Juniors", "Seniors"};

   printf("%-50s %s Available to: %-11s %-3s %s\n",
          course_list->cur->title,
          course_list->cur->course_num,
          years[course_list->cur->avail - 1],
          course_list->cur->days,
          course_list->cur->time);
   fprintf(out, "%-50s %s Available to: %-11s %-3s %s\n",
          course_list->cur->title,
          course_list->cur->course_num,
          years[course_list->cur->avail - 1],
          course_list->cur->days,
          course_list->cur->time);

   if (course_list->next != NULL)
   {
      print_stuff(course_list->next, out);
   }
}
//returns a linked_list sorted by num if 2nd paramter = "num"... or time if 2nd para = "time"
node* sort_by_thing(char* thing, node* course_list, node* sorted_list)
{
   char* c_str; // holds the comparison item

   if (!strcmp(thing, "num")) //if num is chosen
   {
      c_str = course_list->cur->course_num;
   }
   else if (!strcmp(thing, "time"))
   {
      c_str = course_list->cur->time;
   }
   if (course_list->next != NULL)
   {
      return sort_by_thing_helper(
             thing, course_list, course_list->next, course_list->cur, sorted_list);
   }
   else if (sorted_list == NULL) // it won't be null after it recurses from the helper)
   {
      return course_list; /*if there is 1 element, it is already sorted (*/
   }
   else //base case
   {
      add(sorted_list, course_list->cur);
      course_list = del(course_list, course_list->cur);
      return sorted_list;
   }
}
/* finds smallest element, adds to a new list, and deletes from old list and recurses back to
 * sort_by_thing, which continues until the old list is empty */
node* sort_by_thing_helper(char* thing, node* old_list, node* cur_list,
                         course* small_c, node* sorted_list)
{
   char* c_str;
   char* smallest;

   if (!strcmp(thing, "num")) //if num is chosen
   {
      c_str = cur_list->cur->course_num;
      smallest = small_c->course_num;
   }
   else if (!strcmp(thing, "time"))
   {
      c_str = cur_list->cur->time;
      smallest = small_c->time;
   }
   if (strcmp(c_str, smallest) < 0) // if c_str is less than smallest
   {
      small_c = cur_list->cur; //course* with smallest course number
   }
   if (cur_list->next != NULL)
   {
      return sort_by_thing_helper(thing, old_list, cur_list->next, small_c, sorted_list);
   }
   else
   {
      if (sorted_list == NULL)
      {
         sorted_list = make_node(small_c); //need a first element to begin
      }
      else
      {
         add(sorted_list, small_c); //add smallest course num to new sorted list
      }
      old_list = del(old_list, small_c); //remove smallest course from old unsorted list
      return sort_by_thing(thing, old_list, sorted_list); //nested recursion (back to original)
   }
}

// this function just makes a new list that points to the existing courses in the list with MWF
node* list_day_time(char* days_of_week, int time_of_day, node* cur_list, node* new_list)
{
   char* c_day = cur_list->cur->days;
   char* c_time = malloc(sizeof(char)*20);

   strcpy(c_time, cur_list->cur->time); // to avoid mangling my course->cur->time string
   int time_i = atoi(strtok(c_time, "-"));
   int time_bool = (time_i == time_of_day) || (time_of_day == -1);
   //if we don't care about time of day, this function is called with -1 and it ignores it

   if (!strcmp(c_day, days_of_week) && time_bool) // same day of week and time of day
   {
      if (new_list == NULL)
      {
         new_list = make_node(cur_list->cur); // makes a new list if we haven't yet
      }
      else
      {
         add(new_list, cur_list->cur); // adds the course pointer to new list
      }
   }
   if (cur_list->next != NULL)
   {
      return list_day_time(days_of_week, time_of_day, cur_list->next, new_list);
   }
   else
   {
      return new_list;
   }
}
//makes a new list that points to existing courses available to the given year in college
node* list_by_year(int year, node* cur_list, node* new_list)
{
   int c_year = cur_list->cur->avail;
   if (year >= c_year)
   {
      if (new_list == NULL)
      {
         new_list = make_node(cur_list->cur); // makes a new list if we haven't yet
      }
      else
      {
         add(new_list, cur_list->cur); // adds the course pointer to new list
      }
   }
   if (cur_list->next != NULL)
   {
      return list_by_year(year, cur_list->next, new_list);
   }
   else
   {
      return new_list;
   }

}
