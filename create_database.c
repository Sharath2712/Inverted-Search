#include "inverted.h"

int create_database(Dlist *head)
{
    create_HT(arr,27);
    char file_name[100];

    Dlist *temp = head;
    while(temp != NULL)
    {
	strcpy(file_name,temp -> data);
	FILE *file = fopen(file_name,"r");
	char file_word[100];
	while(fscanf(file,"%s",file_word) == 1)
	{
	    if(insert_HT(arr,file_word,file_name,27,head) == FAILURE)
		printf("ERROR : failed to insert word");
	}
	fclose(file);
	temp = temp -> link;
    }
    return SUCCESS;
}
