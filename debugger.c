#include <stdio.h>
#include "headers.h"

/*Debugging functions*/
void debugList(LIST_NODE *head) {
#ifdef DEBUG_LIST
    if (head == NULL) {
        printf("EMPTY QUEUE - no print jobs currently in head \n");
    } else {
        printf("\nCurrent Printer Queue Size: %d \n", getPrinterQueueSize(head));
        LIST_NODE *job = head;
        while (job != NULL) {
            Document *doc =(Document *) job->dataPtr;
            printf("Current Printer Queue: DocNum %d NumofPages %d  PriorityLevel  %d  NumofCycles %d \n",
                   doc->doc_number, doc->no_of_pages,doc->priority, doc->cycle);
            job = job->next;
        }
        printf("---\n END OF LIST\n\n");
    }
#endif
}

void debugAdding(Document *doc) {
#ifdef DEBUG_ADDING
    printf("Adding to Queue - Doc: %d NoPages %d Priority %d \n", doc->doc_number, doc->no_of_pages, doc->priority);
#endif
}

void debugPrinting(Document *doc, int firstPage, int lastPage) {
#ifdef DEBUG_PRINTING_PROCESS
    int i;
    for (i = firstPage; i < lastPage; ++i) {
        printf("PRINTING- DOCUMENT: %d PAGE: %d PRIORITY: %d \n", doc->doc_number, i, doc->priority);

    }
#endif
}

void debugPrintingDone(Document *doc, int cycles) {
    printf("Print Job Completed- Document Number: %d - Cycle Count: %d \n", doc->doc_number, cycles);
}

void debugCycleIncrement(Document *doc) {
#ifdef DEBUG_SHOW_CYCLES
    printf("Increment Cycle - Document: %d Pages: %d Priority: %d Cycle count: %d \n",
           doc->doc_number, doc->no_of_pages, doc->priority, doc->cycle);
#endif
}

void debugCycleExceeded(Document *doc) {
#ifdef DEBUG_SHOW_EXCEEDED
    printf("EXCEEDED CYCLE COUNT - Document: %d Pages: %d Priority: %d Cycle count: %d\n",
           doc->doc_number, doc->no_of_pages, doc->priority, doc->cycle);
#endif
}
