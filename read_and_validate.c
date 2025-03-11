#include "inverted.h"

int read_and_validate(int argc,char *argv[],Dlist **head)
{
    int i;
    for(i = 1;i < argc;i++)
    {
	if(strstr(argv[i],".txt") != NULL)
	{
	    printf("THE FILE CONTAINS THE CORRECT EXTENSION\n");
	    FILE *file = fopen(argv[i],"r");
	    if(file != NULL)
	    {
		printf("FILE IS OPENED SUCCESSFULLY\n");
		int val = fseek(file,0,SEEK_SET);
		if(val != -1)
		{
		    if(*head == NULL)
		    {
			insert_at_last(head,argv[i]);
			printf("FIRST NODE CREATED SUCCESSFULLY\n");
		    }
		    else
		    {
			if(check_duplicate(head,argv,i) == SUCCESS)
			{
			    insert_at_last(head,argv[i]);
			    printf("NODE CREATION SUCCESSFULLY\n");
			}
			else
			    printf("THE FILE IS ALREADY ADDED\n");
		    }
		}
		else
		    printf("THERE IS NO CONTENT IN THE FILE\n");
	    }
	    else
		printf("FILE IS NOT PRESENT\n");
	    fclose(file);
	}
	else
	    printf("THE FILE IS NOT HAVING THE REQUIRED EXTENSION\n");
    }

    return SUCCESS;
}

int check_duplicate(Dlist **head,char *argv[],int i)
{
    if(head == NULL)
    {
	return FAILURE;
    }

    char *str = argv[i];
    Dlist *temp = *head;

    while(temp != NULL)
    {
	if(strcmp(str,temp -> data) == 0)
	    return FAILURE;
	temp = temp -> link;
    }
    return SUCCESS;
}

