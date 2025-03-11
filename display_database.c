#include "inverted.h"

int display_database(Dlist *head,struct hash *arr)
{
    printf("index\tword\tfilecount\tfile_name\tword_count\n\n");
    for(int i = 0;i < 27;i++)
    {
	if(arr[i].ptr == NULL)
	    continue;
	else
	{
	    struct mainnode *tempM = arr[i].ptr;
	    while(tempM != NULL)
	    {
		printf("[%d]\t%s\t%d\t",i,tempM -> word,tempM -> file_count);

		struct subnode *tempS = tempM -> link_S;
		while(tempS != NULL)
		{
		    printf("\t%s\t%d\t",tempS -> file,tempS -> word_count);
		    tempS = tempS -> link_S;
		}
		printf("\n");
		tempM = tempM -> link_M;
	    }
	}
    }
    printf("\n--------------------------------------------------\n");
    print_list(head);
    return SUCCESS;
}
