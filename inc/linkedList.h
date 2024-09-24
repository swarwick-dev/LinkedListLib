/*
 * @file linkedList.h
 * @brief Linked List utility definitions
 *
 * Created on: 25 Aug 2009
 * @author GBY18020
 * @version 0.1
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct LinkedList_ {
		int iListSize;
		long lBytes;
		struct LinkedListNode_ *pFirst;
		struct LinkedListNode_ *pLast;
} LinkedList;

typedef struct LinkedListNode_ {
		struct LinkedListNode_ *pNext;
		void *pData;
} LinkedListNode;

LinkedList *createList();
int addToList(LinkedList *linkedList, void *pData, size_t sDataSize);
void freeList(LinkedList *linkedList);
int insertIntoList(LinkedList *pLinkedList, LinkedListNode *pLinkedListNode, void *pData);

#endif /* LINKEDLIST_H_ */
