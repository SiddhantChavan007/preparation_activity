#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*front,*rear,*temp,*front1;
 
int peekelement();
void enQueue(int data);
void deQueue();
void empty();
void display();
void create();
 
void main()
{
    int data, choice, peekElement;
 
    fprintf(stdout,"\n 1 - Enque");
    fprintf(stdout,"\n 2 - Deque");
    fprintf(stdout,"\n 3 - Peek element");
    fprintf(stdout,"\n 4 - Empty");
    fprintf(stdout,"\n 5 - Exit");
    fprintf(stdout,"\n 6 - Display");
    create();
    while (1)
    {
        fprintf(stdout,"\n Enter choice : ");
        fscanf(stdin,"%d",&choice);
        switch (choice)
        {
        case 1:
            fprintf(stdout,"Enter data :");
            fscanf(stdin,"%d",&data);
            enQueue(data);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            peekElement=peekelement();
            if (peekElement!=0)
                fprintf(stdout,"%d is current element",peekElement);
            else
                fprintf(stderr,"No Current element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        default:
            fprintf(stderr,"Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
 

void create()
{
    front = rear = NULL;
}
 


void enQueue(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->info = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->info = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
}
 

void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        fprintf(stdout,"Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        fprintf(stdout,"%d",front1->info);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        fprintf(stdout,"%d",front1->info);
}

void deQueue()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        fprintf(stderr,"\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            fprintf(stdout,"%d Dequed value",front->info);
            free(front);
            front = front1;
        }
        else
        {
            fprintf(stdout,"%d Dequed value",front->info);
            free(front);
            front = NULL;
            rear = NULL;
        }
}
 
int peekelement()
{
    if ((front != NULL) && (rear != NULL))
        return(front->info);
    else
        return 0;
}
 

void empty()
{
     if ((front == NULL) && (rear == NULL))
        fprintf(stdout,"\n Queue empty");
    else
       fprintf(stdout,"Queue not empty");
}

