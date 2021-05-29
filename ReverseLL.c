#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node* next;
    // Node* next;
}Node;


void push(Node** head, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->val = val;
    newNode->next = (*head);
    *head = newNode;

    // free(newNode);
    return;
}
void printList(Node* head)
{
    Node *temp = head;
    while(temp)
    {
        printf(" %d ->", temp->val);
        temp = temp->next;
    }
    printf(" NULL\n");
}

static void reverse(Node** head)
{
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = *head;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev; //IMPORTANT
    return;
}
// p h
// n 1-2-3-4-x
//   c
int main(void)
{
    Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Given linked list\n");
    printList(head);
    
    reverse(&head);
    printf("\nReversed Linked list \n");
    
    printList(head);

    return 0;
}