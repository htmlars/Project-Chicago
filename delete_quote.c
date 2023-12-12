#include <stdio.h>
#include "struct.h"

void delete_quote(struct Quote quotes[], int *numOfQuotes) {
    if (*numOfQuotes == 0) {
        printf("No quotes to delete!\n");
        return;
    }

    printf("Enter the index of the quote you want to delete (1 to %d):\n", *numOfQuotes);
    int index;
    scanf("%d", &index);

    if (index < 1 || index > *numOfQuotes) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < *numOfQuotes - 1; i++) {
        quotes[i] = quotes[i + 1];
    }

    (*numOfQuotes)--;
    printf("Quote at index %d has been deleted.\n", index);

    FILE *fp = fopen("D:/Semester_1_Projekte/Software/Project_Chicago/quotes.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < *numOfQuotes; i++) {
        if (i != index - 1) {
            fprintf(fp, "\"%s\" (%s, %d) Source: %s | Page: %d\n",
                    quotes[i].quote, quotes[i].author, quotes[i].date,
                    quotes[i].source, quotes[i].page);
        }
    }

    fclose(fp);
}

