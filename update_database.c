#include "inverted.h"

int update_database(Dlist *head)
{
    char file_name[100];
    printf("Enter the file name : ");
    scanf("%s",file_name);
    char str[100];

    struct mainnode *new = malloc(sizeof(struct mainnode));
    if(new == NULL)
	return FAILURE;
    struct subnode *new1 = malloc(sizeof(struct subnode));
    if(new1 == NULL)
	return FAILURE;

    if(strstr(file_name,".txt") != NULL)
    {
	FILE *file = fopen(file_name,"r");
	if(file != NULL)
	{
	    int val = fseek(file,0,SEEK_SET);
	    if(val != -1)
	    {
		char first_char;
		fread(&first_char,1,1,file);
		fseek(file,-1,SEEK_END);
		char last_char;
		fread(&last_char,1,1,file);
		if(first_char == '#' && last_char == '#')
		{
		    while(fgets(str,sizeof(str),file) != NULL)
		    {
			int index = atoi(strtok(str,";"));
			if(arr[index].ptr == NULL)
			{
			    strcpy(new -> word,strtok(NULL,";"));
			    new -> file_count = atoi(strtok(NULL,";"));
			    new -> link_S = NULL;
			    new -> link_M = NULL;
			    arr[index].ptr = new;

			    strcpy(new1 -> file,strtok(NULL,";"));
			    new1 -> word_count = atoi(strtok(NULL,";"));
			    new1 -> link_S = NULL;
			    new -> link_S = new1;
			}
			struct mainnode *tempM = arr[index].ptr;
			struct mainnode *prevM = NULL;
			while(tempM != NULL)
			{
			    struct subnode *tempS = tempM -> link_S;
			    struct subnode *prevS = NULL;
			    while(tempS != NULL)
			    {
				char *str2 = strtok(NULL,";");
				if(strcmp(tempS -> file,str2) != 0)
				{
				    strcpy(new1 -> file,str2);
				    new1 -> link_S = NULL;
				    new1 -> word_count = atoi(strtok(NULL,";"));
				    new1 -> link_S = tempS -> link_S;

				}
				prevS = tempS;
				tempS = tempS -> link_S;
				arr[index].ptr = NULL;
				strcpy(new -> word,strtok(NULL,";"));
				new -> file_count = atoi(strtok(NULL,";"));
				new -> link_S = NULL;
				new -> link_M = NULL;
				arr[index].ptr = new;

				strcpy(new1 -> file,strtok(NULL,";"));
				new1 -> word_count = atoi(strtok(NULL,";"));
				new1 -> link_S = NULL;
				new -> link_S = new1;
			    }
			}
		    }
		}
	    }
	}
	fclose(file);
	return SUCCESS;
    }
}
