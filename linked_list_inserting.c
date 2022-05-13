#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Insert_at_beg(struct node *Start)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int info;
    scanf("%d", &info);
    new_node->data = info;
    new_node->next = Start;
    Start = new_node;
    return Start;
}

struct node *Insert_at_end(struct node *Start)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int info;
    scanf("%d", &info);
    new_node->data = info;
    new_node->next = NULL;
    if (Start == NULL)
    {
        Start = new_node;
    }
    else
    {
        struct node *temp = Start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return Start;
}

struct node *Insert_at_loc(struct node *Start, int loc)
{
    struct node *temp = Start;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int info;
    scanf("%d", &info);
    new_node->data = info;
    if (loc == 1)
    {
        new_node->next = Start;
        Start = new_node;
    }
    else if (loc >= 2 && temp != NULL)
    {
        for (int i = 1; i <= loc - 2; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("INVALID\n");
                return 0;
            }
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    else
    {
        printf("INVALID\n");
    }
}

void printlist(struct node *Start)
{
    while (Start != NULL)
    {
        printf("%d ", Start->data);
        Start = Start->next;
    }
}
int main()
{
    struct node *Start = NULL;
    printf("Enter the number of nodes : ");
    int n;
    scanf("%d", &n);
    printf("Enter the value of nodes :- \n");
    for (int i = 0; i < n; i++)
    {
        // Start = Insert_at_beg(Start);
        Start = Insert_at_end(Start);
    }
    printlist(Start);
    printf("\n");
    // int loc;
    // scanf("%d", &loc);
    // Insert_at_loc(Start, loc);
    // printlist(Start);
    // printf("\n");
    return 0;
}