#include "definitions.h"
#include "headers.h"

int printDocument(Document *document) {

    int cycles = 0; //the number of cycles taken to print the whole document
    int currentCyclePages; //the number of pages that will be processed by the printer in current cycle
    int cycleStartPage = 1; // the first page number for the current cycle


    while (document->no_of_pages > 0) {

        //get how many pages are to be printed on current cycle
        currentCyclePages = PAGESPERMINUTE;

        //if the remaining pages are more than pages per minute
        if (currentCyclePages > document->no_of_pages) {
            //set pages to be printed as the remainder
            currentCyclePages = document->no_of_pages;
        }

        //log the printed pages
        debugPrinting((Document *) document, cycleStartPage, cycleStartPage + currentCyclePages);


        //increment next start page
        cycleStartPage += currentCyclePages;

        //increment cycle by one
        ++cycles;
        //decrement no of pages
        document->no_of_pages -= currentCyclePages;
    }

    return cycles;
}

