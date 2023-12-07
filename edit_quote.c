#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "edit_quote.h"

int edit_quote(struct Quote quotes[], int numOfQuotes) {
    if (numOfQuotes <=  0) {
        printf("No quotes to edit!\n");
        return numOfQuotes;
    }

    int index;
    printf("Enter the index of the quote you want to edit (1 to %d):\n", numOfQuotes);
    scanf("%d", &index);

    if (index < 1 || index > numOfQuotes) {
        printf("Invalid index!\n");
        return numOfQuotes;
    }

    struct Quote *quoteToEdit = &quotes[index - 1];

    int choice;
    printf("Select an aspect to edit:\n");
    printf("1. Quote\n");
    printf("2. Author\n");
    printf("3. Date\n");
    printf("4. Source\n");
    printf("5. Page\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the updated quote:\n");
            while (getchar() != '\n');
            if (fgets(quoteToEdit->quote, sizeof(quoteToEdit->quote), stdin) == NULL) {
                perror("Error reading quote.\n");
                return numOfQuotes;
            }
            size_t len = strlen(quoteToEdit->quote);
            if (quoteToEdit->quote[len - 1] == '\n') {
                quoteToEdit->quote[len - 1] = '\0';
            }
            break;
        case 2:
            printf("Enter the updated author:\n");
            while (getchar() != '\n');
            if (fgets(quoteToEdit->author, sizeof(quoteToEdit->author), stdin) == NULL) {
                perror("Error reading author.\n");
                return numOfQuotes;
            }
            len = strlen(quoteToEdit->author);
            if (quoteToEdit->author[len - 1] == '\n') {
                quoteToEdit->author[len - 1] = '\0';
            }
            break;
        case 3:
            printf("Enter the updated date:\n");
            scanf("%d", &quoteToEdit->date);
            break;
        case 4:
            printf("Enter the updated source:\n");
            while (getchar() != '\n');
            if (fgets(quoteToEdit->source, sizeof(quoteToEdit->source), stdin) == NULL) {
                perror("Error reading source.\n");
                return numOfQuotes;
            }
            len = strlen(quoteToEdit->source);
            if (quoteToEdit->source[len - 1] == '\n') {
                quoteToEdit->source[len - 1] = '\0';
            }
            break;
        case 5:
            printf("Enter the updated page:\n");
            scanf("%d", &quoteToEdit->page);
            break;
        default:
            printf("Invalid choice!\n");
            return numOfQuotes;
    }

    printf("Quote at index %d has been updated.\n", index);
    return numOfQuotes;
}
