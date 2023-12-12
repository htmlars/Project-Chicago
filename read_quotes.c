#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "read_quotes.h"

int read_quotes(struct Quote quotes[], int maxQuotes) {
    FILE *fp = fopen("D:/Semester_1_Projekte/Software/Project_Chicago/quotes.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading!\n");
        return 0;
    }

    int index = 0;
    char line[1000];
    while (fgets(line, sizeof(line), fp) != NULL && index < maxQuotes) {
        line[strcspn(line, "\n")] = '\0';

        char quote[1000], author[100], source[100];
        int date, page;

        if (sscanf(line, "\"%999[^\"]\" (%99[^,], %d) Source: %99[^|] | Page: %d",
                   quote, author, &date, source, &page) == 5) {
            strcpy(quotes[index].quote, quote);
            strcpy(quotes[index].author, author);
            quotes[index].date = date;
            strcpy(quotes[index].source, source);
            quotes[index].page = page;

            index++;
        } else {
            printf("Error parsing line %d\n", index + 1);
        }
    }

    fclose(fp);
    return index;
}
