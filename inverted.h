#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H


struct hash
{
    int index;
    struct mainnode *ptr;
};
extern struct hash arr[27];
#define SUCCESS 0
#define FAILURE -1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stddef.h>
typedef struct node
{
    struct node *link;
    char data[100];
}Dlist;

struct mainnode
{
    int file_count;
    char word[100];
    struct subnode *link_S;
    struct mainnode *link_M;
};

struct subnode
{
    int word_count;
    char file[100];
    struct subnode *link_S;
};

int read_and_validate(int argc,char *argv[],Dlist **head);
int check_duplicate(Dlist **head,char *argv[],int i);
int insert_at_last(Dlist **head, char *data);
void create_HT(struct hash *HT, int size);
int insert_HT(struct hash *arr,const char *word,const char *filename,int size,Dlist *head);
void print_list(Dlist *head);
int check_word_case(Dlist *head);
int create_database(Dlist *head);
int display_database(Dlist *head,struct hash *arr);
int search_database(Dlist *head);
int save_database(Dlist *head,struct hash *arr);
int update_database(Dlist *head);

#endif
