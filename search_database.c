#include "inverted.h"

int search_database(Dlist *head)
{
    char read[100];
    printf("Enter the word which you want to search : ");
    scanf("%s",read);

    int index;
    if(read[0] >= 'a' && read[0] <= 'z')
	index = read[0] - 97;
    else if(read[0] >= 'A' && read[0] <= 'Z') 
	index = read[0] - 65;
    else
	index = 27;

    struct mainnode *tempM = arr[index].ptr;
    struct subnode *tempS = tempM -> link_S;

    while(tempM -> link_M != NULL)
    {
	if(strcmp(tempM -> word,read) == 0)
	{
	    printf("The word %s is present in %d file.The file is ",read,tempM -> file_count);
	    while(tempS != NULL)
	    {
		printf("%s,%d times.",tempS -> file,tempS -> word_count);
		tempS = tempS -> link_S;
	    }
	}
	tempM = tempM -> link_M;
    }
    printf("\n");
    return SUCCESS;
}
