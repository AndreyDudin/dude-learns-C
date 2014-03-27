#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;

} node;

typedef node *list_t;

list_t create_list (const char *);
void print_list (list_t list);
int line_size(list_t list);
int word_quantity(list_t list);
int spaces_qua(list_t list);
void process_line(list_t list);


int main()
{
    char buf[81];
    list_t list;
    scanf("%80[^\n]", buf);
    fflush(stdin);
    list = create_list(buf);
    process_line(list);

    print_list(list);
    return 0;

}

void process_line(list_t list)
{
    list_t space;
    list_t head;
    list_t first;
    list_t l_word;
    list_t cur;
    int spaces_in_begin, len, spaces_qu, common_spaces, extra_spaces;

    int wrd, j, i;

    spaces_in_begin = spaces_quantity(list);
    len = line_size(list);
    wrd = word_quantity(list);
    spaces_qu = 80 - len + spaces_in_begin;
    common_spaces = spaces_qu / (wrd - 1);
    extra_spaces = spaces_qu % (wrd - 1);

    j = 0;
    while (list->data == ' ' && list != NULL)
    {
        first = list;
        list = list->next;
        free(first);
    }
    cur = list;


    while (cur != NULL)
    {

        while (cur->data != ' ' && cur->data != 0)
        {
            l_word = cur;
            cur = cur->next;
        }
        j++;
        if (j < wrd)
        {


            for (i = 0; i < common_spaces; i++)
            {
                l_word->next = (node *)malloc(sizeof(node));
                l_word = l_word->next;
                l_word->data = ' ';
            }
            if (j < extra_spaces)
            {
                l_word->next = (node *)malloc(sizeof(node));
                l_word = l_word->next;
                l_word->data = ' ';
            }
            l_word = cur;
        }
        while (cur->data == ' ' && cur != NULL)
        {
            space = cur;
            cur = cur->next;
            free(space);
        }

    }

}

list_t create_list (const char *str)
{
    node head;
    node *last = &head;
    while (*str != '\0')
    {
        last->next = (node *)malloc(sizeof(node));
        last = last->next;
        last->data = *str++;
        last->next = NULL;

    }
    return head.next;
}



int line_size(list_t list)
{
    int length = 0;
    while (list != NULL)
    {
        length++;
        list = list->next;
    }
    return length;
}

int word_quantity(list_t list)
{
   int wrd=0;
   while(list != NULL)
   {
   		if ((list->data!=' ' && list==NULL) || (list->data!=' ' && (list->next->data==' '))
   		{
   			wrd++;
   		}
   		list=list->next;
   }
}

int spaces_quantity(list_t list)
{
    int sp = 0;
    while (list != NULL)
    {
        if (list -> data == ' ')
        {
            sp++;
        }
        list = list->next;
    }
    return sp;

}


void print_list (list_t list)
{
    for (; list != NULL; list = list->next)
    {
        printf("%c", list->data);
    }
    printf("\n");
}

