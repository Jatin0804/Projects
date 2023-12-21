#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct doubly
{
    struct doubly *back;
    int data;
    struct doubly* next;
}dll;

dll *start,*link,*new,*temp,*tt;

int main(void)
{
    int ch;
    start=NULL;

    printf("Program for DOUBLY linked list.");
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
        new=(dll*)malloc(sizeof(dll));

        if(new==NULL)
        {
            printf("Memory not allocated.");
            exit(1);
        }

        printf("\nEnter Data for node[%d] : ",n);
        scanf("%d",&new->data);

        new->next=NULL;
        new->back=NULL;

        if(start==NULL)
        {
            start=new;
            link=new;
        }
        else
        {
            link->next=new;
            new->back=link;
            link=link->next;
        }
        printf("You want to continue (Y/N) : ");
        choice=getche();
    }
    printf("\n");
}

display()
{
  /*  link=start;

    printf("\nThe data inserted is : ");
    while(link->next!=NULL)
    {
        printf("%d \t",link->data);
        link=link->next;
        temp=link;
    }
    printf("%d",temp->data);
    printf("\nThe data  in reverse order is : ");

    while(link!=NULL)
    {
        printf("%d \t",link->data);
        link=link->back;
    }
    printf("\n");*/

    link=start;
    printf("Forward : ");
    while(link!=NULL)
    {
      printf("%d",link->data );
      temp=link;
      link=link->next;
    }
    printf("\nBackward : ");

    while(temp!=NULL)
    {
      printf("%d",temp->data );
      temp=temp->back;
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

int n,c=1;
printf("\nEnter the position of node :");
scanf("%d",&n);

if(n==1)
{
    temp=(dll*)malloc(sizeof(dll));
    if(temp==NULL)
    {
        printf("Memory not allocated.");
        exit(1);
    }
    temp->back=NULL;
    temp->next=NULL;

    printf("Enter data to be inserted at node[%d]: ",n);
    scanf("%d",&temp->data);
    temp->next=start;
    start->back=temp;
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

    temp=(dll*)malloc(sizeof(dll));
    if(temp==NULL)
    {
        printf("Memory not allocated.");
        exit(1);
    }
    temp->back=NULL;
    temp->next=NULL;

    printf("Enter data to be inserted at node[%d]: ",n);
    scanf("%d",&temp->data);

    tt=link->next;
    temp->next=tt;
    temp->back=link;
    tt->back=temp;
    link->next=temp;
}
printf("\n");
}

delete()
{

int n,c=1;
printf("Enter the position of node :");
scanf("%d",&n);

if(n==1)
{
    temp=start;
    start=start->next;
    start->back=NULL;
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
    tt=temp->next;
    tt->back=link;
    link->next=tt;
    free(temp);
}
printf("\n");
}
