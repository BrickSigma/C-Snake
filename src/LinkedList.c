#include <LinkedList.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *newNode(int x, int y)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

LinkedList *newLinkedList()
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

Node *getHead(LinkedList *list)
{
    return list->head;
}

Node *getTail(LinkedList *list)
{
    return list->tail;
}

void insertHead(LinkedList *list, Node *newNode)
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

void insertTail(LinkedList *list, Node *newNode)
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

Node *removeHead(LinkedList *list)
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

Node *removeTail(LinkedList *list)
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

void traverseLinkedList(LinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }

    Node *current = (Node *)list->head;
    do
    {
        printf("%d %d\n", current->x, current->y);
        current = (Node *)current->next;
    } while (current != NULL);
}

void forEachLinkedList(LinkedList *list, void (*func)(Node *))
{
    if (list->head == NULL)
    {
        return;
    }
    Node *current = (Node *)list->head;
    do
    {
        func(current);
        current = (Node *)current->next;
    } while (current != NULL);
}

bool anyLinkedList(LinkedList *list, Node *cmp, bool (*func)(Node *, Node *))
{
    if (list->head == NULL)
    {
        return false;
    }
    Node *current = (Node *)list->head;
    do
    {
        if (func(current, cmp))
        {
            return true;
        }
        current = (Node *)current->next;
    } while (current != NULL);
    return false;
}

void clearLinkedList(LinkedList *list)
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

void deleteLinkedList(LinkedList *list)
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

    free(list);
}