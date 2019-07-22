
void run_menu(node* first, FILE* out);
void print_stuff(node* course_list, FILE* out);
node* sort_by_thing(char* thing, node* course_list, node* sorted_list);
node* sort_by_thing_helper(char* thing, node* old_list, node* cur_list,
                         course* small_c, node* sorted_list);
node* list_day_time(char* days_of_week, int time_of_day, node* cur_list, node* new_list);
node* list_by_year(int year, node* cur_list, node* new_list);
