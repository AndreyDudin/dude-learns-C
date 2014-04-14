#include <stdio.h>
#include <stdlib.h>



typedef struct Item
{
    int key;
    int release;
    char *info;
    struct Item *next;
} Item;

Item *add_element(Item *head) // по условию элемент вставляется в начало списка

{
    char *str[80];
    Item *current, *temp, *nxt;

    Item element;

    int k, version;

    printf("Введите ключ нового элемента");
    scanf("%d", k);
    printf("Введите информацию");
    scanf("%80[\n]", str);

    temp = (Item *)malloc(sizeof(Item));
    temp->key = k;
    temp->info = *str;
    current = head;

    while (current->next != NULL) //определяе версию элемента
    {
        if (current->key == k)
        {
            temp->release = current->release + 1;
        }


    }
    if (temp->release < 1)
    {
        temp->release = 1;
    }

    if (head->next == NULL) //вставка в начало если голова единственный элемент
    {
        head->next = temp;
        temp->next = NULL;
    }
    if (head->next != NULL) //если не единственный
    {
        nxt = head->next;
        head->next = temp;
        temp->next = nxt;
    }




}
void search(Item *head)
{
    Item *current = head;
    int k, version;
    printf("Введите ключ\n");
    scanf("%d\n", k);
    printf("Введите версию, для поиска всех версий введите 999\n");
    scanf("%d\n", version);

    if (version < 999)
    {
        while (current != 0)
        {
            if (current->key == k && current->release == version)
                printf("%d %d %s", current->key, current->release, current->info);
            current = current->next;
        }
    }

    if (version == 999)
    {
        while (current != 0)
        {
            if (current->key == k)
                printf("%d %d %s", current->key, current->release, current->info);
            current = current->next;
        }
    }


}


int main()
{
    Item head = {0, 0, '\0', NULL};
}