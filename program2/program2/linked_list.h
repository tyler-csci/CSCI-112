
struct node
{
   course* cur;
   struct node* prev;
   struct node* next;
};
typedef struct node node;

node* make_node(course* c);
void add(node* a, course* new_course);
int list_length(node* a);
node* del(node* a, course* rem_c);
