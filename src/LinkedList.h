#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

/**
 * Node structure
 *
 * @param x x position of node
 * @param y y position of node
 * @param next pointer to next node
 */
typedef struct Node
{
    int x, y;
    struct Node *next;
} Node;

/**
 * Linked list structure
 *
 * @param head pointer to head of list
 * @param tail pointer to tail of list
 */
typedef struct LinkedList
{
    Node *head;
    Node *tail;
} LinkedList;

/**
 * Used to create a new node.
 *
 * @param x x position of node
 * @param y y position of node
 */
Node *NewNode(int x, int y);

/**
 * Used to create a new linked list.
 *
 * @returns Pointer to the new linked list. Returns `NULL` on error.
 */
LinkedList *LinkedListNew();

/**
 * Get the pointer to the head node of the linked list.
 */
Node *LinkedListGetHead(LinkedList *list);

/**
 * Get the pointer to the tail node of the linked list.
 */
Node *LinkedListGetTail(LinkedList *list);

/**
 * Insert a new node at the head of a linked list.
 *
 * @param list
 * @param newNode
 */
void LinkedListInsertHead(LinkedList *list, Node *newNode);

/**
 * Insert a new node at the tail of a linked list.
 *
 * @param list
 * @param newNode
 */
void LinkedListInsertTail(LinkedList *list, Node *newNode);

/**
 * Remove the head node of the linked list.
 *
 * @returns The pointer to the head node. Returns `NULL` if the list is empty.
 */
Node *LinkedListRemoveHead(LinkedList *list);

/**
 * Remove the tail node of the linked list.
 *
 * @returns The pointer to the tail node. Returns `NULL` if the list is empty.
 */
Node *LinkedListRemoveTail(LinkedList *list);

/**
 * Used to output the contents of the linked list.
 */
void LinkedListTraverse(LinkedList *list);

/**
 * Used to call a function on every item/node in the linked list.
 *
 * @param list
 * @param func function pointer to process node, eg: `void func(Node *node) {...}`
 */
void LinkedListForEach(LinkedList *list, void (*func)(Node *));

/**
 *  Compare the elements of the linked list with the `cmp` argument node.
 *
 * @param list
 * @param cmp Value to compare elements to
 * @param func Function used to compare the nodes, first parameter should be the element in the linked list, the second parameter is the `cmp` node.
 *
 * @return `true` if any one element satisfies the condition, or `false` if otherwise.
 */
bool LinkedListContains(LinkedList *list, Node *cmp);

/**
 * Delete all the nodes from the linked list.
 */
void LinkedListClear(LinkedList *list);

/**
 * Delete the entire linked list. This will also delete and free all the nodes within the list.
 */
void LinkedListDelete(LinkedList *list);

#endif