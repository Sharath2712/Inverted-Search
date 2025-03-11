#include "inverted.h"

int  save_database(Dlist *head,struct hash *arr)
{
    char file_name[100];
    printf("Enter the file name : ");
    scanf("%s",file_name);
    FILE *file = fopen(file_name, "w");
    if(strstr(file_name,".txt") != NULL)
    {
	for(int i = 0;i < 27;i++)
	{
	    if(arr[i].ptr == NULL)
		continue;
	    else
	    {
		struct mainnode *tempM = arr[i].ptr;
		while(tempM != NULL)
		{
		    fprintf(file,"#%d;%s;%d;",i,tempM -> word,tempM -> file_count);
		    struct subnode *tempS = tempM -> link_S;
		    while(tempS != NULL)
		    {
			fprintf(file,"%s;%d;#",tempS -> file,tempS -> word_count);
			tempS = tempS -> link_S;
		    }
		    fprintf(file,"\n");
		    tempM = tempM -> link_M;
		}
	    }
	}
    }
    else
    {
	printf("THE FILE DOES NOT CONTAINS THE REQUIRED EXTENSION\n");
    }
    fclose(file);
    return SUCCESS;
}
