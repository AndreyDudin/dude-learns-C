#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;

} node;

typedef node *list_t;

list_t create_list(const char *);
void print_list(list_t);
int str_len(list_t);
int count_words(list_t);
list_t process_line(list_t);
list_t add_spaces(list_t, int);

int main()
{
    char buf[81];
    list_t list;
    scanf("%80[^\n]", buf);
    fflush(stdin);
    list = create_list(buf);
    list = process_line(list);
    print_list(list);
    return 0;
}

list_t process_line(list_t list)
{
    int processed_words = 0;
    int words = count_words(list);
    int length = str_len(list);
    int common_spaces = (80 - length + words - 1) / (words - 1);
    int extra_spaces = (80 - length + words - 1) % (words - 1);
    list_t current = list;

    while (current != NULL)
    {
        if (current->data == ' ')
        {
            if (processed_words < extra_spaces)
            {
                current = add_spaces(current, common_spaces);
            }
            else
            {
                current = add_spaces(current, common_spaces - 1);
            }
        }
        current = current->next;
    }

    return list;
}

list_t create_list(const char *str)
{
    node head = {' ', NULL};
    node *last = &head;
    while (*str != '\0')
    {
        if ((*str == ' ' || *str == '\t') && (last->data == ' ' || last->data == '\t' || *(str + 1) == '\0'))
        {
            str++;
        }
        else
        {
            last->next = (node *)malloc(sizeof(node));
            last = last->next;
            if (*str == '\t')
            {
                last->data = ' ';
            }
            else
            {
                last->data = *str++;
            }
            last->next = NULL;
        }
    }
    return head.next;
}

int str_len(list_t list)
{
    int length = 0;
    for (; list != NULL; list = list->next)
    {
        length++;
    }
    return length;
}

int count_words(list_t list)
{
    int words = 0;
    for (; list != NULL; list = list->next)
    {
        if (list->data != ' ' && (list->next == NULL || list->next->data == ' '))
        {
            words++;
        }
    }
    return words;
}

void print_list(list_t list)
{
    for (; list != NULL; list = list->next)
    {
        printf("%c", list->data);
    }
    printf("\n");
}

list_t add_spaces(list_t list, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        list_t temp = (node *)malloc(sizeof(node));
        temp->data = ' ';
        temp->next = list->next;
        list->next = temp;
        list = temp;
    }
    return list;
}