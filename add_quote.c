#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "add_quote.h"

const int MAX_QUOTES = 100;

int add_quote(struct Quote quotes[], int *numOfQuotes) {
    if (*numOfQuotes >= MAX_QUOTES) {
        printf("Maximum number of quotes reached!\n");
        return *numOfQuotes;
    }

    FILE *fp = fopen("D:/Semester_1_Projekte/Software/Project_Chicago/quotes.txt", "a");
    if (fp == NULL) {
        perror("Error opening file!\n");
        return *numOfQuotes;
    }

    printf("Enter the quote:\n");
    if (fgets(quotes[*numOfQuotes].quote, sizeof(quotes[*numOfQuotes].quote), stdin) == NULL) {
        perror("Error reading quote.\n");
        fclose(fp);
        return *numOfQuotes;
    }
    quotes[*numOfQuotes].quote[strcspn(quotes[*numOfQuotes].quote, "\n")] = '\0';
    fprintf(fp, "\"%s\"", quotes[*numOfQuotes].quote);

    printf("Enter the author:\n");
    if (fgets(quotes[*numOfQuotes].author, sizeof(quotes[*numOfQuotes].author), stdin) == NULL) {
        perror("Error reading author.\n");
        fclose(fp);
        return *numOfQuotes;
    }
    quotes[*numOfQuotes].author[strcspn(quotes[*numOfQuotes].author, "\n")] = '\0';
    fprintf(fp, " (%s,", quotes[*numOfQuotes].author);

    printf("Enter the date of publication:\n");
    if (scanf("%d", &quotes[*numOfQuotes].date) != 1) {
        perror("Invalid input for date.\n");
        fclose(fp);
        return *numOfQuotes;
    }
    while (getchar() != '\n');
    fprintf(fp, " %d)", quotes[*numOfQuotes].date);

    printf("Enter the source:\n");
    if (fgets(quotes[*numOfQuotes].source, sizeof(quotes[*numOfQuotes].source), stdin) == NULL) {
        perror("Error reading source.\n");
        fclose(fp);
        return *numOfQuotes;
    }
    quotes[*numOfQuotes].source[strcspn(quotes[*numOfQuotes].source, "\n")] = '\0';
    fprintf(fp, "  Source: %s | ", quotes[*numOfQuotes].source);

    printf("Enter the page:\n");
    if (scanf("%d", &quotes[*numOfQuotes].page) != 1) {
        perror("Invalid input for page.\n");
        fclose(fp);
        return *numOfQuotes;
    }
    while (getchar() != '\n');
    fprintf(fp, "Page: %d\n", quotes[*numOfQuotes].page);

    fclose(fp);
    (*numOfQuotes)++;
    printf("Quote was added!\n");

    return *numOfQuotes;
}


