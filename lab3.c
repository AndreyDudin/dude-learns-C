#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


const int ALL_VERSIONS = 0;
typedef struct Item
{
    int key;
    int release;
    char *info;
    struct Item *next;
} Item;
typedef Item *list_t;


list_t delete_one(list_t head, int k, int version);
list_t delete_all(list_t head, int k);
list_t search(list_t head);
list_t delete_t(list_t head);
list_t print_t(list_t head);
list_t add_element(list_t head);

int main()
{


    int k, version;
    int i = 0;
    char *str[80];
    list_t temp;
    list_t head;
    setlocale (LC_ALL, "Rus");
    for (;;)
    {
        list_t list =  NULL;
        while (i < 3)
        {
            list = add_element(list);
            i++;

        }
        list = print_t(list);
        list = delete_t(list);
        list = print_t(list);

    }
    return 0;

}


list_t delete_t(list_t head)
{
    int k;
    int version;

    list_t new_head;
    printf("vvedite klych\n");
    scanf("%d", &k);
    fflush(stdin);
    printf("Vvedite version, for delete enter 0\n");
    scanf("%d", &version);
    fflush(stdin);
    if (version == ALL_VERSIONS)
    {
        new_head = delete_all(head, k);
    }
    if (version != ALL_VERSIONS)
    {
        new_head = delete_one(head, k, version);
    }
    return new_head;
}

list_t print_t(list_t head)
{
    list_t current;
    current = head;
    while (current != NULL)
    {
        printf("%d %d %s ", current->key, current->release, &(current->info));
        current = current->next;
    }
    return head;
}


list_t add_element(list_t head)
{

    list_t current;
    list_t new_head = (Item *)malloc(sizeof(Item));
    int k;

    char *str[80];
    printf("Vvedite klych\n");
    scanf("%d", &k);
    fflush(stdin);;
    printf("Vvedite info\n");
    scanf("%80[^\n]", str);
    fflush(stdin);


    new_head->next = head;
    new_head->info = *str;
    new_head->key = k;
    current = head;
    new_head->release = 1;

    while ( current != NULL)
    {
        if (current->key == k)
        {
            new_head->release = current->release + 1;
            break;
        }
        current = current->next;



    }

    return new_head;


}

list_t delete_one(list_t head, int k, int version)
{
    list_t current;
    list_t temp;
    list_t prev;

    if (head == NULL)
    {
        printf("Таблица пуста\n");
        return head;
    }
    else
    {
        if (head->key == k && head->release == version)
        {
            temp = head;
            head = head->next;
            free(temp->info);
            free(temp);
            return head;
        }
        current = head->next;
        prev = head;
        while (current != NULL)
        {
            if (current->key == k && current->release == version)
            {
                temp = current;
                prev->next = current->next;
                free(temp->info);
                free(temp);
                return head;


            }
            current = current->next;
            prev = prev->next;
        }

    }

    return head;

}
list_t delete_all(list_t head, int k)
{
    list_t current;
    list_t temp;
    list_t prev;
    if (head == NULL)
    {
        printf("Таблица пуста\n");
        return head;
    }
    else
    {
        while (head->key == k && head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp->info);
            free(temp);
        }
        if (head == NULL)
        {
            return head;
        }
        else
        {
            prev = head;
            current = head->next;
            while (current != NULL)
            {
                if (current->key == k)
                {
                    temp = current;
                    prev->next = current->next;
                    current = current->next;
                    free(temp->info);
                    free(temp);

                }
                else
                {
                    current = current->next;
                    prev = prev->next;
                }

            }
        }


    }
    return head;


}




list_t search(list_t head)
{
    list_t current;
    int k, version;
    current = head;

    printf("Vvedite kluch dlya poiska\n");
    scanf("%d", &k);
    fflush(stdin);
    printf("Vvedite version for search all 0\n");
    scanf("%d", &version);
    fflush(stdin);


    if (version != ALL_VERSIONS)
    {
        while (current != NULL)
        {
            if (current->key == k && current->release == version)
                printf("%d %d %s", current->key, current->release, &(current->info));
            current = current->next;

        }

    }

    if (version == ALL_VERSIONS)
    {
        while (current != NULL)
        {
            if (current->key == k)
                printf("%d %d %s", current->key, current->release, &(current->info));
            current = current->next;
        }
    }
    return head;


}


