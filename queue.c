#include<stdio.h>

int q[5], i, item, size, front = -1, rear = -1;

void enqueue(int item)
{
    if(rear == size - 1)
    {
        printf("queue is full\n");
    }
    else
    {
        if(rear == -1)
        {
            front = 0;
            rear = 0;
            q[rear] = item;
        }
        else
        {
            rear = rear + 1;
            q[rear] = item;
        }
    }
}

void dequeue()
{
    if ((front == -1) || (front > rear))
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("deleted item is: %d\n", q[front]);
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
    }
}

void display()
{
    if(front == -1)
    {
        printf("queue is empty\n");
    }
    else
    {
        for(i = front; i <= rear; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice;
    printf("enter the size: ");
    scanf("%d", &size);

    do
    {
        printf("\nenter the choice\n");
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("enter the item to be inserted:\n");
                scanf("%d", &item);
                enqueue(item);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("exit\n");
                break;
            }
            default:
                printf("invalid choice\n");
        }
    }
    while(choice != 4);
}
