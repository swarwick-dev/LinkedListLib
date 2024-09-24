/*
 * @file linkedList.c
 * @brief Linked List utility code
 *
 * Created on: 25 Aug 2009
 * @author GBY18020
 * @version 0.1
 */

#include "linkedList.h"
#include "Logger.h"
#include <cstdlib>
#include <cstring>
#include <malloc.h>

/**
 * @fn LinkedList * createList()
 *
 * @brief Function to allocate a new linked list
 *
 * @return LinkedList* The newly allocated list
 *
 * @author Simon Warwick
 * @version 0.1
 */
LinkedList *createList()
{
	LinkedList *result = NULL;
	result = (LinkedList *) malloc(sizeof(LinkedList));
	if (result == NULL) {
		return NULL;
	}
	result->iListSize = 0;
	result->pFirst = NULL;
	result->pLast = NULL;
	return result;
}

/**
 * @fn int addToList(LinkedList *linkedList,void *pData)
 *
 * @brief Function to add a new node to the linked list
 *
 * @param linkedList LinkedList* The list to add to
 * @param pData void* The data item to add
 *
 * @return LinkedList* The newly allocated list
 *
 * @author Simon Warwick
 * @version 0.1
 */
int addToList(LinkedList *linkedList, void *pData, size_t sDataSize)
{
	int retVal = 0;
	LinkedListNode tempPtr;

	if ((linkedList != NULL) && (linkedList->iListSize == 0)) /* List is empty, so add a new node */
	{
		linkedList->pFirst = (LinkedListNode *) malloc(sizeof(struct LinkedListNode_));

		if (linkedList->pFirst == NULL) {
			return 1;
		}
		/* Populate the first node's structure variables */
		linkedList->pFirst->pData = (void *) malloc(sDataSize);
		if (linkedList->pFirst->pData == NULL) {
			gl_error("Unable to allocate memory to data structure:LinkedListNode->pData");
			return 1;
		}
		memset(linkedList->pFirst->pData, 0, sDataSize);
		memcpy(linkedList->pFirst->pData, pData, sDataSize);
		/*linkedList->pFirst->pData = pData;*/
		linkedList->pFirst->pNext = NULL;

		linkedList->iListSize++;
		linkedList->pLast = linkedList->pFirst;
		linkedList->lBytes = sDataSize;
		return retVal;
	}
	else if (linkedList != NULL) /* List is not empty, so check for a match */
	{
		/* Adding new bc seq to the end of the NempList */
		linkedList->pLast->pNext = (LinkedListNode *) malloc(sizeof(struct LinkedListNode_));
		if (linkedList->pLast->pNext == NULL) {
			printf("Unable to allocate memory to data structure:LinkedListNode");
			return 1;
		}
		linkedList->pLast = linkedList->pLast->pNext;

		linkedList->pLast->pData = (void *) malloc(sDataSize);
		if (linkedList->pLast->pData == NULL) {
			gl_error("Unable to allocate memory to data structure:LinkedListNode->pData");
			return 1;
		}
		memset(linkedList->pLast->pData, 0, sDataSize);
		memcpy(linkedList->pLast->pData, pData, sDataSize);
		/*linkedList->pLast->pData = pData;*/
		linkedList->pLast->pNext = NULL;

		linkedList->iListSize++;
		linkedList->lBytes += sDataSize;
		return retVal;
		/* Finished adding new bc seq to the end of the NempList */
	}
	else {
		return 1;
		/*List is not initialised */
	}
}

/**
 * @fn void freeList(LinkedList *linkedList)
 *
 * @brief Function to deallocate the linked list
 *
 * @param linkedList LinkedList* The list to deallocate
 *
 * @author Simon Warwick
 * @version 0.1
 */
void freeList(LinkedList *linkedList)
{
	LinkedListNode *currNodePtr = NULL;
	LinkedListNode *nextNodePtr = NULL;

	if (linkedList != NULL) {
		currNodePtr = linkedList->pFirst;
		while (currNodePtr != NULL) {
			nextNodePtr = currNodePtr->pNext;

			free(currNodePtr->pData);
			free(currNodePtr);

			currNodePtr = NULL;
			currNodePtr = nextNodePtr;
		}

		free(linkedList);
		linkedList = NULL;
	}
}
