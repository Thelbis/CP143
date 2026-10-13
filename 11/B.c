#include "B.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int numReadings;
  ListNodePtr startFrontAddLL = NULL, startBackAddLL = NULL;

  while (1) {
    printf("Enter the number of readings (1 to 24): ");
    scanf("%d", &numReadings);

    if (numReadings >= 1 && numReadings <= MAX_HOURS) break;

    printf("Entered value not withing range.\n");
  }

  for (int i = 0; i < numReadings; i++) {
    Reading data;
    printf("Enter the hour, temperature and humidity: ");
    scanf("%d %lf %lf", &data.hour, &data.temperature, &data.humidity);

    addNodeAtFront(&startFrontAddLL, data);
    addNodeAtBack (&startBackAddLL,  data);
  }
  printf("\n");

  int countFront, countBack;
  countFront = countNodes(startFrontAddLL);
  countBack  = countNodes(startBackAddLL);

  printf("List built with addNodeAtFront (%d nodes)\n", countFront);
  printList(startFrontAddLL);
  printf("\n");

  printf("List built with addNodeAtBack (%d nodes)\n",  countBack);
  printList(startBackAddLL);
  printf("\n");

  printf("Clearing both lists...\n");
  clearList(&startFrontAddLL);
  clearList(&startBackAddLL );

  countFront = countNodes(startFrontAddLL);
  countBack  = countNodes(startBackAddLL);
  printf("The first list now contains %d nodes:\n", countFront);
  printf("The list is empty.\n");
  printf("The second list now contains %d nodes:\n", countBack);
  printf("The list is empty.\n");
}

void addNodeAtFront(ListNodePtr *startPtrPtr, Reading data) {
  ListNodePtr newPtr = malloc(sizeof(ListNode));
  if (newPtr == NULL) {
    printf("malloc failed\n");
    return;
  }

  newPtr->data = data;
  newPtr->nextPtr = *startPtrPtr;
  *startPtrPtr = newPtr;
  return;
}

void addNodeAtBack(ListNodePtr *startPtrPtr, Reading data) {
  ListNodePtr newPtr = malloc(sizeof(ListNode));
  if (newPtr == NULL) {
    printf("malloc failed\n");
    return;
  }

  newPtr->data = data;
  newPtr->nextPtr = NULL;

  if (*startPtrPtr == NULL) {
    *startPtrPtr = newPtr;
    return;
  }

  ListNodePtr currentPtr = *startPtrPtr;
  while (currentPtr->nextPtr != NULL) {
    currentPtr = currentPtr->nextPtr;
  }
  currentPtr->nextPtr = newPtr;
  return;
}

void printList(ListNodePtr startPtr) {
  ListNodePtr currentPtr = startPtr;

  printf("Hour  Temp (degC)  Humidity (%%)\n");
  while (currentPtr != NULL) {
    printf("%4d  %11.1f  %12.1f\n", currentPtr->data.hour, currentPtr->data.temperature, currentPtr->data.humidity);

    currentPtr = currentPtr->nextPtr;
  }
}

int countNodes(ListNodePtr startPtr) {
  int count = 0;
  ListNodePtr currentPtr = startPtr;

  while (currentPtr != NULL) {
    count++;
    currentPtr = currentPtr->nextPtr;
  }

  return count;
}

void clearList(ListNodePtr *startPtrPtr) {
  while (*startPtrPtr != NULL) {
    ListNodePtr tempPtr = *startPtrPtr;
    *startPtrPtr = (*startPtrPtr)->nextPtr;
    free(tempPtr);
  }
}
