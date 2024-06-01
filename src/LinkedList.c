#include <LinkedList.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *NewNode(int x, int y)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

LinkedList *LinkedListNew()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL)
    {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node *LinkedListGetHead(LinkedList *list)
{
    return list->head;
}

Node *LinkedListGetTail(LinkedList *list)
{
    return list->tail;
}

void LinkedListInsertHead(LinkedList *list, Node *newNode)
{
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return;
    }
    newNode->next = list->head;
    list->head = (Node *)newNode;
    return;
}

void LinkedListInsertTail(LinkedList *list, Node *newNode)
{
    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return;
    }
    list->tail->next = newNode;
    list->tail = newNode;
}

Node *LinkedListRemoveHead(LinkedList *list)
{
    if (list->head == NULL)
    {
        return NULL;
    }
    else if (list->head->next == NULL)
    {
        Node *head = list->head;
        list->head = NULL;
        list->tail = NULL;
        return head;
    }
    else
    {
        Node *head = list->head;
        list->head = head->next;
        head->next = NULL;
        return head;
    }
}

Node *LinkedListRemoveTail(LinkedList *list)
{
    if (list->head == NULL)
    {
        return NULL;
    }

    Node *current = list->head;
    Node *previous = NULL;
    while (current->next != NULL)
    {
        previous = current;
        current = (Node *)current->next;
    }

    if (previous == NULL)
    {
        list->head = NULL;
        list->tail = NULL;
        return current;
    }

    previous->next = NULL;
    list->tail = previous;
    return current;
}

void LinkedListTraverse(LinkedList *list)
{
    for (Node *node = list->head; node; node = node->next)
    {
        printf("%d %d\n", node->x, node->y);
    }
}

void LinkedListForEach(LinkedList *list, void (*func)(Node *))
{
    for (Node *node = list->head; node; node = node->next)
    {
        func(node);
    }
}

bool LinkedListContains(LinkedList *list, Node *cmp)
{
    for (Node *node = list->head; node; node = node->next)
    {
        if (node->x == cmp->x && node->y == cmp->y)
        {
            return true;
        }
    }
    return false;
}

void LinkedListClear(LinkedList *list)
{
    if (list->head != NULL)
    {
        Node *current = list->head;
        do
        {
            Node *toDelete = current;
            current = (Node *)current->next;
            free(toDelete);
        } while (current != NULL);
    }
    list->head = NULL;
    list->tail = NULL;
}

void LinkedListDelete(LinkedList *list)
{
    LinkedListClear(list);

    free(list);
}