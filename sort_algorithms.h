#ifndef SORT_ALGORITHMS_H
#define SORT_ALGRITHMS_H

#include <vector>
#include <algorithm> 
#include <string> 
using namespace std; 



struct Book {
    string title;
    double rating;
    };

void selection_sort(vector<Book>& books) {
int size = books.size();
    for (int i = 0; i < size - 1; i++) {
    int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (books[j].rating < books[min_idx].rating) {
            min_idx = j;
            }
        }
    std::swap(books[i], books[min_idx]);
    }
}




#endif // SORT_ALGORITHMS_H