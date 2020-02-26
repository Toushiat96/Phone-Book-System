#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[20];
    char number[15];
    struct node *next;
};
struct node *head=NULL, *last=NULL;

int k;

//This function to store.

char insert(char names[], char numbers[])
{
    struct node *tmp;

    tmp=(struct node *)malloc(sizeof(struct node));

    strcpy(tmp->name,names);
    strcpy(tmp->number,numbers);
    tmp->next=NULL;

    //for the first element in the list
    if(head==NULL)
    {
        head=tmp;
        last=tmp;
    }
    else
    {
        last->next=tmp;
        last=tmp;
    }
}

//this function to print the all words.
char printlist()
{

    struct node *tmp=head;
    int i=1;
    printf("Your contacs are:\n");
    while(tmp!=NULL)
    {
        printf("\n\t%d. %s\n",i,tmp->name);
        printf("\t   %s\n", tmp->number);
        tmp=tmp->next;
        i++;
    }
}

int search(char name[])
{
    struct node *tmp=head;
    while(tmp != NULL)
    {
        if(strcmp(tmp->name, name)==0)
        {
            printf("%s\n%s\n", tmp->name, tmp->number);
            return ;
        }
        tmp=tmp->next;
    }
    return ;
}

char delete(char name[])
{
    struct node *tmp=head,*fd;
    k=0;
    int i;

    while(tmp != NULL)
    {
        k++;
        if(strcmp(tmp->name, name)==0)
        {
            break;
        }
        else
        {
            tmp=tmp->next;
        }

    }

    printf("\nposition %d",k);

    tmp=head;
    while(tmp!=NULL)
    {
        if(k==1)
        {
            fd = head->next;
            head=fd;
            break;
        }
        else
        {
            for(i=0;i<k-2;i++)
            {
                tmp=tmp->next;
            }
            fd = tmp->next;
            tmp->next = fd->next;
            free(fd);
            break;
        }
    }
}


int main()
{
    system("color 5a");
    printf("\t\t\twelcome to phone book project\t\t\t\n");
    char name[20], number[15], search_name[20];
    int i=15, t;
    printf("\t1   for create new contact\n");
    printf("\t2   for see your contact list\n");
    printf("\t3   for search\n");
    printf("\t4   for Delete contract\n");
    printf("\t0   for break\n");
    while(1)
    {
        scanf("%d", &i);
        if(i==0)
        {
            break;
        }
        else if(i==1)
        {
            printf("Enter your name\n");
            scanf("%s", name);
            printf("Enter your number\n");
            scanf("%s", number);
            insert(name, number);
        }
        else if(i==2)
        {
            printlist();
        }
        else if(i==3)
        {
            printf("Enter name for seach \n");
            scanf("%s", search_name);
            search(search_name);

        }
        else if(i==4)
        {
            printf("Enter name for delete \n");
            scanf("%s", search_name);
            delete(search_name);
        }
        else
        {
            printf("\n  ***Enter correct direction***\n");
        }
        printf("\nEnter directions\n");
    }
}
