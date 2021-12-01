#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "headers.h"
#include "definitions.h"


int main() {
    srand(time(NULL));

    LIST_NODE *head = NULL;

    int printingFrequency = (ITERATIONS * 10 / 100) - 1;
    int nextPrinting = printingFrequency;
    for (int i = 0; i < ITERATIONS; ++i) {

        LIST_NODE *node= createPrinterJob(i + 1);
        addJobToPrinterQueue(&head, &node);

        // for every 10% of total docs, process a printer job //TODO this is hackish probability impl
        if (nextPrinting == i) {
            nextPrinting += printingFrequency;
            processNextPrinterJob(&head);
            printf("\n");
        }
    }

    //print a message to indicate program has completed
    printf("End of Program - *  @Mimimidotsuser * \n");
    printf("Number of printer jobs left in queue:  %d \n", getPrinterQueueSize(head));

    return 0;
}
