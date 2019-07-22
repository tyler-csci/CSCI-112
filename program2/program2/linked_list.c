
#include "course.h"
#include "main.h"
struct node
{
   course* cur;
   struct node* prev;
   struct node* next;
};
typedef struct node node;

void del_helper(node* cur_n, const course* rem_c);

node* make_node(course* c)
{
   node* a = (node*) malloc(sizeof(node));
   a->cur = c;
   a->next = NULL;
   a->prev = NULL;
   return a;
}
void add(node* a, course* new_course)
{
   if (a->next == NULL)
   {
      a->next = make_node(new_course);
      a->next->prev = a; //set the new node's prev to the last node from before
   }
   else
   {
      add(a->next, new_course);
   }
}

int list_length(node* a)
{
   if (a->next == NULL)
   {
      return 1;
   }
   else
   {
      return 1 + list_length(a->next);
   }
}
node* del(node* a, course* rem_c)
{
   if (a->cur == rem_c)
   {
      return a->next; // removing the first element (return the rest)
   }
   else if (a->next != NULL)
   {
      del_helper(a->next, rem_c);
   }
   return a; /* I must return the linked list in case I delete the first element, otherwise,
   the calling function would lose access to the linked list */
}

// used if remove element isnt the first
void del_helper(node* cur_n, const course* rem_c)
{
   if (cur_n->cur == rem_c)
   {
      cur_n->prev->next = cur_n->next; //skipping over cur_n
      if (cur_n->next != NULL)
      {
         cur_n->next->prev = cur_n->prev; //skipping over cur_n
      }
   }
   else if (cur_n->next != NULL)
   {
      del_helper(cur_n->next, rem_c);
   }
}

