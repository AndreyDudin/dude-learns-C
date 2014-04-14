#include <stdio.h>
#include <stdlib.h>



typedef struct Item
{
    int key;
    int release;
    char *info;
    struct Item *next;
} Item;
typedef Item *list;

list add_element(list head, char *inf, int k);
void search(list head,int k,int version); 




int main()
{
    Item head =  NULL;
}




list add_element(list head, char *inf, int k) 
{
	list new_head;
	list current;
	list new_head=malloc(sizeof(Item));
	new_head->next=head;
	new_head->info=inf;
	new_head->key=k;
	current=new_head;
	while( current->next != NULL)
	{
		if(current->key==k)
		{
			new_head->release=current->release+1;
			break;
		}


	}
	if(new_head->release<1)
	{
		new_head->release=1;
	}

	}




void search(list head,int k,int version)
{
   	list current;
   	current=head;
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


