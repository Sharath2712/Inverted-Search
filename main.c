#include "inverted.h"

struct hash arr[27];

int main(int argc, char *argv[])
{

    Dlist *head = NULL;
    if(argc < 2)
    {
	printf("ERROR : Sufficient number of CLA is not passed");
	return FAILURE;
    }
    else
    {
	if(read_and_validate(argc,argv,&head) == FAILURE)
	    return FAILURE;
    }


    printf(" 1.CREATE DATABASE\n 2.DISPLAY DATABASE\n 3.SEARCH DATABASE\n 4.SAVE DATABASE\n 5.UPDATE DATABASE\n 6.EXIT\n");


    while(1)
    {
	int option;
	printf("Enter the option : ");
	scanf("%d",&option);

	switch(option)
	{
	    case 1:
		{
		    if(head == NULL)
			printf("ERROR");
		    if(create_database(head) == SUCCESS)
		    {
			printf("Database created successfully\n");
		    }
		    else
		    {
			printf("Database creation failure\n");
		    }
		    break;
		}
	    case 2:
		{
		    if(display_database(head,arr) == SUCCESS)
		    {
			printf("Database display SUCCESSFULL\n");
		    }
		    else
		    {
			printf("Database display FAILURE\n");
		    }
		    break;
		}
	    case 3:
		{
		    if(search_database(head) == SUCCESS)
		    {
			printf("The data is found\n");
		    }
		    else
		    {
			printf("The data is not found\n");
		    }
		    break;
		}
	    case 4:
		{
		    if(save_database(head,arr) == SUCCESS)
		    {
			printf("Database saved successfull\n");
		    }
		    else
		    {
			printf("Database was not saved\n");
		    }
		    break;
		}
	    case 5:
		{
		    if(update_database(head) == SUCCESS)
		    {
			printf("Update database successfull\n");
		    }
		    else
		    {
			printf("Update database failure\n");
		    }
		    break;
		}
	    case 6:
		{
		    return SUCCESS;
		}
	    default :
		{
		    printf("INVALID OPTION\n");
		}
	}
    }
    return SUCCESS;
}
