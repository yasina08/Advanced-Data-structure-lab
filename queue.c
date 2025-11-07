#include<stdio.h>
int q[5],i,item,size,front=-1,rear=-1;
void enqueue(int item)
{
    if(rear==size)
    {
        printf("queue is full\n");
    }
    else
    {
        if(rear==-1)
        {
            front=0;
            rear=0;
            q[rear]=item;
        }
        else
        {
            rear=rear+1;
            q[rear]=item;
        }
    }
}
void dequeue()
{
    if ((front==-1)&&(rear==1))
    {
        printf("queue is empty\n");
    }
    else
    {
        if(front==rear)
        {
            printf("deleted item is: %d",q[front]);
            front=-1;
            rear=-1;
        }
        else
        {
            item=q[front];
            printf("deleted item is :%d",q[front]);
            front=front+1;
        }

    }
}
void display()
{
    for(i=front;i<=rear;i++)
    {
        printf("%d ",q[i]);
    }
}
void main()
{
    int choice;
    printf("enter the size:");
    scanf("%d",&size);
    do
    {
        printf("\nenter the choice\n");
        printf("\n 1.enqueue\n 2.dequeue\n 3.display\n 4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("enter the item to be inserted:\n");
                scanf("%d",&item);
                enqueue(item);
                break;
            }
            case 2:
            {
                dequeue(item);
                break;
            }
            case 3:
            {
                display(item);
                break;
            }
            case 4:
            {
                printf("exit");
                break;
            }
            default:printf("invalid choice\n");
        }
    }
    while(choice!=4);
}