#include "inverted.h"

int insert_at_last(Dlist **head,char *data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
	return FAILURE;
    strcpy(new -> data,data);
    new->link = NULL;

    if(*head == NULL)
    {
	*head = new;
	return SUCCESS;
    }
    Dlist *temp = *head;
    while(temp->link != NULL)
    {
	temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}
void print_list(Dlist *head)
{
    if (head == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	while (head)
	{
	    printf("%s -> ", head -> data);
	    head = head -> link;
	}

	printf("NULL\n");
    }
}

void create_HT(struct hash *HT, int size)
{
    for(int i = 0;i < size;i++)
    {
	HT[i].index = i;
	HT[i].ptr  = NULL;
    }
}


int insert_HT(struct hash *arr,const char *word,const char *filename,int size,Dlist *head)
{
    int index,count_file = 1,count_word = 1;
    int val = check_word_case(head);
    struct mainnode *new = malloc(sizeof(struct mainnode));
    if(new == NULL)
	return FAILURE;
    struct subnode *new1 = malloc(sizeof(struct subnode));
    if(new1 == NULL)
	return FAILURE;



    if(isdigit(word[0]))
	index = 26;
    else
    {
	if(val == 0)
	    index = word[0] % 65;
	else if(val == 1)
	    index = word[0] % 97;
    }


    if(arr[index].ptr == NULL)
    {
	new -> file_count = count_file;
	strcpy(new -> word,word);
	new -> link_S = NULL;
	new -> link_M = NULL;
	arr[index].ptr = new;


	new1 -> word_count = count_word;
	strcpy(new1 -> file,filename);
	new1 -> link_S = NULL;
	new -> link_S = new1;
	return SUCCESS;
    }
    struct mainnode *tempM = arr[index].ptr;
    struct mainnode *prevM = NULL;
    while(tempM != NULL)
    {
	if(strcmp(tempM -> word,word) == 0)
	{
	    struct subnode *tempS = tempM -> link_S;
	    struct subnode *prevS = NULL;
	    while(tempS != NULL)
	    {
		if(strcmp(tempS -> file,filename) == 0)
		{
		    tempS -> word_count++;
		    return SUCCESS;
		}
		prevS = tempS;
		tempS = tempS -> link_S;
	    }
	    prevS -> link_S = new1;
	    new1 -> word_count = count_word;
	    strcpy(new1 -> file,filename);
	    new1 -> link_S = NULL;
	    return SUCCESS;
	}
	prevM = tempM;
	tempM = tempM->link_M;
    }
    prevM -> link_M = new;
    new -> file_count = count_file;
    strcpy(new -> word,word);
    new -> link_S = new1;
    new -> link_M = NULL;

    new1 -> word_count = count_word;
    strcpy(new1 -> file,filename);
    new1 -> link_S = NULL;

    return SUCCESS;
}

int check_word_case(Dlist *head)
{
    Dlist *temp = head;
    while(temp != NULL)
    {
	FILE *file = fopen(temp -> data,"r");
	if(file == NULL)
	{
	    temp = temp -> link;
	    continue;
	}

	char check[100];
	while(fscanf(file,"%99s",check) == 1)
	{
	    if(isupper(check[0]))
		return 0;
	    else if(islower(check[0]))
		return 1;
	}
	fclose(file);
	temp = temp -> link;
    }
}
