#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct singly
{
    int data;
    struct singly* next;
}sll;

sll *start,*link,*new;

int main(void)
{
    int ch;
    start=NULL;

    printf("Program for SINGLY linked list.");
    do
    {
        printf("\nOptions Available : ");
        printf("\n1.Create \n2.Display \n3.Count \n");
        printf("4.Insert \n5.Delete \n6.Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:count();
            break;
            case 4:insert();
            break;
            case 5:delete();
            break;
            default:exit(0);
        }
    }while(1);
}

create()
{
    int n=0;
    char choice='y';
    while(choice=='y'||choice=='Y')
    {
        n++;
        new=(sll*)malloc(sizeof(sll));

        if(new==NULL)
        {
            printf("Memory not allocated.");
            exit(1);
        }

        printf("\nEnter Data for node[%d] : ",n);
        scanf("%d",&new->data);

        new->next=NULL;

        if(start==NULL)
        {
            start=new;
            link=new;
        }
        else
        {
            link->next=new;
            link=new;
            //link=link->next;
        }
        printf("You want to continue (Y/N) : ");
        choice=getche();
    }
    printf("\n");
}

display()
{
    link=start;

    printf("\nThe data inserted is : ");
    while(link!=NULL)
    {
        printf("%d \t",link->data);
        link=link->next;
    }
    printf("\n");
}

count()
{
    link=start;
    int sum=0;

    while(link!=NULL)
    {
        sum=sum+1;
        link=link->next;
    }
    printf("\nThe number of nodes are : %d",sum);
    printf("\n");
}

insert()
{
    /*char choice='y';
    while(choice=='y'||choice=='Y')
    {
        new=(sll*)malloc(sizeof(sll));
         if(new==NULL)
        {
            printf("Memory not allocated.");
            exit(1);
        }

        printf("\nEnter Data : ");
        scanf("%d",&new->data);

        new->next=NULL;

        if(start==NULL)
        {
            start=new;
            link=new;
        }
        else
        {
            link->next=new;
            link=link->next;
        }

        printf("Enter your choice : ");
        choice=getche();

    }

    //create a new node

    int val;

    new = malloc(sizeof(sll));

    printf("Enter data : ");
    scanf("%d",&val);
    new->data = val;
    new->next     = NULL;

    //if head is NULL, it is an empty list
    if(start == NULL)
       start = new;
    //Otherwise, find the last node and add the newNode
    else
    {
        sll *lastNode = start;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        link->next = new;
    }

*/

sll *temp;
int n,c=1;
printf("\nEnter the position of node :");
scanf("%d",&n);

if(n==1)
{
    temp=(sll*)malloc(sizeof(sll));
    if(temp==NULL)
    {
        printf("Memory not allocated.");
        exit(1);
    }
    printf("Enter data to be inserted at node[%d]: ",n);
    scanf("%d",&temp->data);
    temp->next=start;
    start=temp;
}

if(n>1)
{
    link=start;
    while(link != NULL && c != n-1)
    {
        c++;
        link=link->next;
    }

    temp=(sll*)malloc(sizeof(sll));
    if(temp==NULL)
    {
        printf("Memory not allocated.");
        exit(1);
    }
    printf("Enter data to be inserted at node[%d]: ",n);
    scanf("%d",&temp->data);
    temp->next=link->next;
    link->next=temp;
}
printf("\n");
}

delete()
{
sll *temp;
int n,c=1;
printf("Enter the position of node :");
scanf("%d",&n);

if(n==1)
{
    temp=start;
    start=start->next;
    free(temp);
}

if(n>1)
{
    link=start;
    while(link != NULL && c != n-1)
    {
        c++;
        link=link->next;
    }

    temp=link->next;
    link->next=temp->next;
    free(temp);
}
printf("\n");
}
