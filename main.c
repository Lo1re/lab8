#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "book.h"

#define SIZE 100

int main(void) {
    Book books[SIZE];
    FILE* file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("problem with file\n");
        return 1;
    }
    int count = 0;
    char line[256];
    while (count < SIZE) {
        if (fgets(books[count].author, sizeof(books[count].author), file) == NULL) break;
        trim_newline(books[count].author);
        if (fgets(books[count].title, sizeof(books[count].title), file) == NULL) break;
        trim_newline(books[count].title);
        if (fgets(line, sizeof(line), file) == NULL) break;
        if (sscanf(line, "%d", &books[count].year) != 1) break;
        if (fgets(line, sizeof(line), file) == NULL) break;
        if (sscanf(line, "%d", &books[count].pages) != 1) break;
        if (fgets(line, sizeof(line), file) == NULL) break;
        if (sscanf(line, "%f", &books[count].price) != 1) break;
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("file incorrect\n");
        return 0;
    }

    printTable(books, count);

    select_sort_year(books, count);
    printf("\nSorted by year:\n");
    printTable(books, count);

    select_sort_pages(books, count);
    printf("\nSorted by pages:\n");
    printTable(books, count);

    for (int i = 0; i < 3 && i < count; i++) {
        printf("\nBook %d details:\n", i + 1);
        printBook(&books[i]);
    }

    return 0;
}
