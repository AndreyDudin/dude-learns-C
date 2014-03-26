#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;

} node;

typedef node *list_t;

list_t create_list (const char *);
void print_list (list_t);
int line_size(list_t);

int main()
{
    char buf[81];
    list_t list;
    scanf("%80[^\n]", buf);
    fflush(stdin);
    list = create_list(buf);
    print_list(list);
    printf("%d\n", line_size(list));




    return 0;

}

void process_line(list_t list)
{
    list_t space, head, first, l_word;
    int sp, len, spaces_qu, common_spaces, extra_spaces, wrd, j;
    sp = spaces_qu(list);
    len = line_size(list);
    wrd = word_quantity(list);
    spaces_qu = 80 - len + sp;
    common_spaces = spaces / (wrd - 1);
    extra_spaces = spaces % (wrd - 1);

    while (list->data == ' ' && list != NULL)
    {
        first = list;
        list = list->next;
        free(first);
    }
    head = list;

    while (list != NULL)
    {

        while (list->data != ' ' && list->data != 0)
        {
            l_word = list;
            list = list->next;
        }
        for (i = 0; i < common_spaces; i++)
        {
            l_word->next = (node *)malloc(sizeof(node));
            l_word = l_word->next;
            l_word->data = ' ';

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
    int wrd = 0;
    while (list != NULL)
    {
        if ((list->data != ' ' && list->next->data == ' ') || (list->data != ' ' && list->next->data == 0))
        {
            wrd++
        }
    }
    return wrd;
}

int spaces_qu(list_t list)
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

