#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int data;
	struct Queue *next;
};

struct Queue *front=NULL;
struct Queue *rear=NULL;
int count=0;


void enQueue(int data)
{
	if(rear==NULL)
	{
		rear=(struct Queue *)malloc(1*sizeof(struct Queue));
		rear->next=NULL;
		rear->data=data;
		front=rear;
	}

	else
	{
		struct Queue *temp;
		temp=(struct Queue *)malloc(1*sizeof(struct Queue));
		rear->next=temp;
		temp->data=data;
		temp->next=NULL;
		rear=temp;

	}
	count++;
}


void deQueue()
{
	struct Queue *temp=front;
	if(front==NULL)
	{
		fprintf(stderr,"\nTrying remove from an empty queue\n");
	}
	else
	{
		if(front->next!=NULL)
		{
			front=temp->next;
			fprintf(stdout,"\nRemoved element is %d from queue\n",temp->data);
			free(temp);
		}
		else
		{
			fprintf(stdout,"\nRemoved element is %d from queue\n",front->data);
			free(front);
			front=NULL;
			rear=NULL;
		}
	}
	count--;
}

void getSize()
{
	fprintf(stdout,"%d element are there in a queue\n",count);
}

void getFront()
{
	if(front==NULL)
		fprintf(stderr,"No front element : Queue is empty\n");
	else
		fprintf(stdout,"The front element is %d\n",front->data);
}

void reverse(int tillElement)
{
	struct Queue *pre=NULL;
	struct Queue *curr=front;
	struct Queue *nextt=NULL;
	struct Queue *sfront=NULL;

	int i;
	if (tillElement>count)
		fprintf(stderr,"%d out of Queue range\n",tillElement);
	else
	{
		for(i=1,sfront=front;i<=tillElement;sfront=sfront->next,i++);
		
		while(curr!=sfront)
		{
			nextt=curr->next;
			curr->next=pre;
			pre=curr;
			curr=nextt;
		}
		if(pre==rear)
		{
			rear=front;
			front=pre;
		}
		else if(curr==sfront)
		{
			front->next=sfront;
			front=pre;
		}
		
	}
}

void display()
{
    struct Queue *front1=front;

    if ((front1 == NULL) && (rear == NULL))
    {
        fprintf(stdout,"Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        fprintf(stdout," %d->",front1->data);
        front1 = front1->next;
    }
    if (front1 == rear)
        fprintf(stdout," %d ",front1->data);
}



void main()
{
    int data, choice,tillElement;
    fprintf(stdout,"\n1 - Enqueue\n2 - Dequeue\n3 - Get Front\n4 - Get Size\n5 - Reverse\n6 - Display\n7 - EXIT");
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
            getFront();
	    break;
        case 4:
            getSize();
            break;
        case 5:
            fprintf(stdout,"Enter number of element\n");
            fscanf(stdin,"%d",&tillElement);
            reverse(tillElement);
            break;
        case 6:
            display();
            break;
	case 7:
	    exit(0);
        default:
            fprintf(stderr,"Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}


