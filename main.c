#include <stdio.h>
#include "add_quote.h"
#include "display_quote.h"
#include "struct.h"
#include "edit_quote.h"
#include "delete_quote.h"
#include "read_quotes.h"

int main() {
    const int MAX_QUOTES = 100;
    struct Quote quotes[MAX_QUOTES];
    int numOfQuotes = read_quotes(quotes, MAX_QUOTES);
    int option;

    do {
        printf("(1) Add Quote\n(2) Edit Quote\n(3) Display Quote\n(4) Delete Quote\n(5) Save and Exit\n");
        scanf("%d", &option);
        while (getchar() != '\n');

        switch (option) {
            case 1:
                if (numOfQuotes < MAX_QUOTES) {
                    numOfQuotes = add_quote(quotes, &numOfQuotes);
                } else {
                    printf("Maximum number of quotes reached!\n");
                }
                break;
            case 2:
                edit_quote(quotes, numOfQuotes);
                break;
            case 3:
                display_quote(quotes, numOfQuotes);
                break;
            case 4:
                delete_quote(quotes, &numOfQuotes);
                break;
            case 5:
                printf("Quotes saved! Bye..\n");
                break;
            default:
                printf("Not a valid option!\n");
        }
    } while (option > 0 && option < 5);

    return 0;
}



