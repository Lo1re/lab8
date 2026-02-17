#ifndef BOOK_H
#define BOOK_H

typedef struct {
    char author[50];
    char title[50];
    int year;
    int pages;
    float price;
} Book;

void swap(Book array[], long pos1, long pos2);
void select_sort_year(Book array[], long size);
void select_sort_pages(Book array[], long size);
void printBook(const Book* b);
void printTable(const Book* b, int n);
void trim_newline(char* s);

#endif
#pragma once
