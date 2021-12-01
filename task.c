#include <stdlib.h>
#include <stdio.h>
#include "definitions.h"
#include "headers.h"

LIST_NODE *createPrinterJob(int docNumber) {

    //create new printerJobNode
    LIST_NODE *printerJobNode = malloc(sizeof(LIST_NODE));

    printerJobNode->dataPtr = malloc(sizeof(Document)); //allocate memory for document data
    printerJobNode->next = NULL; // the next should point to a null

    printerJobNode->dataPtr->cycle = 0;
    printerJobNode->dataPtr->doc_number = docNumber;
    printerJobNode->dataPtr->no_of_pages = 1 + (rand() % MAXPAGES);
    printerJobNode->dataPtr->priority = 1 + (rand() % 3);
    printerJobNode->dataPtr->cyclesExceed = 0; //false

    return printerJobNode;
}

void addJobToPrinterQueue(LIST_NODE **head, LIST_NODE **printerJobNode) {
    debugAdding(((Document *) (*printerJobNode)->dataPtr));


    //if we are inserting at the start
    if (*head == NULL) {
        *head = *printerJobNode;
    } else {
        //else, check where to assign the job to

        LIST_NODE *currentPrintJobNode;
        currentPrintJobNode = *head;

        // seek upto end i.e. where next is null
        while (currentPrintJobNode->next != NULL) {
            currentPrintJobNode = currentPrintJobNode->next;
        }

        //point the last PrintJobNode next to the new PrintJobNode
        currentPrintJobNode->next = *printerJobNode;
    }

}

int getPrinterQueueSize(LIST_NODE *head) {

    int count = 0;
    LIST_NODE *currentPrintJobNode = head;
    while (currentPrintJobNode != NULL) {
        count++;
        currentPrintJobNode = currentPrintJobNode->next;
    }
    return count;
}

void processNextPrinterJob(LIST_NODE **head) {
    debugList(*head);

    static LIST_NODE *activeJob;

    //check if there is a document being processed and there are printing jobs
    if (activeJob != NULL || *head == NULL) {
        return;
    }

    // pop the first job
    activeJob = *head;

    //make the next job as current head
    *head = activeJob->next;

    int cyclesTaken = printDocument(activeJob->dataPtr);
    debugPrintingDone(activeJob->dataPtr, cyclesTaken);

    //clear the job
//    activeJob = NULL;
    free(activeJob->dataPtr);
    free(activeJob);

    //increment the cycle count for each print job request in the queue
    incrementCycle(head, cyclesTaken);

}

void incrementCycle(LIST_NODE **head, int cyclesTaken) {

    LIST_NODE *current = (LIST_NODE *) *head;
    while (current != NULL) {
        debugCycleIncrement((Document *) current->dataPtr);

        //do the actual increment
        ((Document *) current->dataPtr)->cycle += cyclesTaken;

        // if document cycles is greater than max cycles, and we have not recorded the change, call the debugger
        if (((Document *) current->dataPtr)->cycle > MAXCYCLES &&
            ((Document *) current->dataPtr)->cyclesExceed != 0) {
            debugCycleExceeded(current->dataPtr);
            //record cycle has exceeded
            ((Document *) current->dataPtr)->cyclesExceed = 1;
        }


        current = current->next;
    }
}


