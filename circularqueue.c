#include <stdio.h>

#define SIZE 5

int Q[SIZE], front = -1, rear = -1;

void enqueue(int item)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("The queue is full\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        Q[rear] = item;
        printf("%d", item);
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The deleted item is: %d\n", Q[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", Q[i]);
    }
    else
    {
        for (int i = front; i < SIZE; i++)
            printf("%d ", Q[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", Q[i]);
    }
    printf("\n");
}

int main()
{
    int choice, item;
    do
    {
        printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}