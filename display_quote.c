#include <stdio.h>
#include "struct.h"
#include "display_quote.h"

void display_quote(const struct Quote quotes[], int numOfQuotes) {
    if (numOfQuotes == 0) {
        printf("No quotes to display!\n");
        return;
    }

    printf("Enter the index of the quote you want to display (1 to %d):\n", numOfQuotes);
    int index;
    scanf("%d", &index);

    if (index < 1 || index > numOfQuotes) {
        printf("Invalid index!\n");
        return;
    }

    while (getchar() != '\n');

    printf("Quote: %s\n", quotes[index - 1].quote);
    printf("Author: %s\n", quotes[index - 1].author);
    printf("Date: %d\n", quotes[index - 1].date);
    printf("Source: %s\n", quotes[index - 1].source);
    printf("Page: %d\n\n", quotes[index - 1].page);
}
