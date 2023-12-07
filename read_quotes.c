#include <stdio.h>
#include "read_quotes.h"

int read_quotes(struct Quote quotes[], int maxQuotes) {
    FILE *fp = fopen("quotes.txt", "r");
    if (fp == NULL) {
        perror("Error opening file!\n");
        return 0;
    }

    int count = 0;
    while (count < maxQuotes && fscanf(fp, "%[^|]|%[^|]|%d|%[^|]|%d\n",
                                       quotes[count].quote, quotes[count].author, &quotes[count].date,
                                       quotes[count].source, &quotes[count].page) == 5) {
        count++;
    }

    fclose(fp);
    return count;
}