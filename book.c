#include "book.h"
#include <stdio.h>
#include <string.h>

void swap(Book array[], long pos1, long pos2) {
    Book temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

void select_sort_year(Book array[], long size) {
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (array[j].year < array[min_index].year) {
                min_index = j;
            }
        }
        if (min_index != i) swap(array, i, min_index);
    }
}

void select_sort_pages(Book array[], long size) {
    int i, j, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (array[j].pages < array[min_index].pages) {
                min_index = j;
            }
        }
        if (min_index != i) swap(array, i, min_index);
    }
}

void printBook(const Book* b) {
    printf("Author: %s\n", b->author);
    printf("Title: %s\n", b->title);
    printf("Year: %d\n", b->year);
    printf("Pages: %d\n", b->pages);
    printf("Price: %.2f\n", b->price);
}

void trim_newline(char* s) {
    if (!s) return;
    s[strcspn(s, "\r\n")] = '\0';
}

void printTable(const Book* b, int n) {
    const int authorW = 25;
    const int titleW = 30;
    const int yearW = 6;
    const int pagesW = 7;
    const int priceW = 10;

    printf("\n%-*s %-*s %*s %*s %*s\n",
        authorW, "Author",
        titleW, "Title",
        yearW, "Year",
        pagesW, "Pages",
        priceW, "Price");

    int totalWidth = authorW + 1 + titleW + 1 + yearW + 1 + pagesW + 1 + priceW;
    for (int i = 0; i < totalWidth; ++i) putchar('-');
    putchar('\n');

    for (int i = 0; i < n; i++) {
        printf("%-*s %-*s %*d %*d %*.2f\n",
            authorW, b[i].author,
            titleW, b[i].title,
            yearW, b[i].year,
            pagesW, b[i].pages,
            priceW, b[i].price);
    }
    printf("\ncount of records:%d\n", n);
}
