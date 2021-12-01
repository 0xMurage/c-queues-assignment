#ifndef INC_1889915_HEADERS_H
#define INC_1889915_HEADERS_H

typedef struct document {
    int doc_number;
    int priority;
    int no_of_pages;
    int cycle;
    int cyclesExceed;

} Document;

typedef struct node {
    Document *dataPtr; //pointer to a print job
    struct node *next; //next linked print job
} LIST_NODE;


LIST_NODE *createPrinterJob(int docNumber);

void addJobToPrinterQueue(LIST_NODE **list, LIST_NODE **printerJob);

int getPrinterQueueSize(LIST_NODE *list);

void processNextPrinterJob(LIST_NODE **list);

int printDocument(Document *document);

void incrementCycle(LIST_NODE **list, int cycles);

void clearList(LIST_NODE **list);

void debugList(LIST_NODE *list);

void debugAdding(Document *document);

void debugPrinting(Document *document, int startPage, int lastPage);

void debugPrintingDone(Document *document, int cycles);

void debugCycleIncrement(Document *document);

void debugCycleExceeded(Document *);

#endif //INC_1889915_HEADERS_H
