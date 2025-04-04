#include <iostream>
#include "single_include\nlohmann\json.hpp" // Include the JSON library (nlohmann/json)
#include "search_algorithms.h"
#include "sort_algorithms.h"
#include <vector>
#include <string>
#include <algorithm> 
#include <chrono> 
#include <fstream> 
using json = nlohmann::json;
using namespace std; 

//Easier to read code
// I don't have to repeat the whole chrono::duration<double> everytime
typedef chrono::duration<double> Duration; 

//A function to load the books 
vector<Book> loadbooks(const string& filename){
//Open the file for reading
ifstream file(filename); 
//Create a Json object to strore Json data
json booksJson; 
//Read the file as text, parse the text into Json data and store in the Json object
file >> booksJson; 
vector<Book> books; 

//For each Json object (temporarily stored in book) add the title to our books vector
for (const auto& book : booksJson){
    string title = book["title"].get<string>();
    double rating = book.contains("rating") ? book["rating"].get<double>() : 0; 
    books.push_back({title,rating});
}
return books; 
}

//funtion to display the books
void display_books(const vector<Book>& books, int count){
    for(int i = 0; i < count; i++){
        cout << books[i].title << " (Rating: " << books[i].rating << " )" << endl; 
    }
}




int main() {
// Load Dataset 
vector<Book> books = loadbooks("data\\books.json");
 
//Extract sorted titles
vector<string> sorted_titles; 
for(const auto& book : books){
    sorted_titles.push_back(book.title);
}
sort(sorted_titles.begin(), sorted_titles.end()); 

//Binary search Prompt
string book_to_search; 
cout << "\n----Chapter 1: Binary Search ----" << endl; 
cout << "Enter the name of book title you want to search for: ";  
getline(cin,book_to_search); 

//Measure the time taken to perform the request
auto start_time = chrono::high_resolution_clock::now(); 
int index = binary_search(sorted_titles, book_to_search); 
auto end_time = chrono::high_resolution_clock::now(); 
chrono::duration<double> time_taken = end_time - start_time; 

if (index != -1){
cout << "The book " + book_to_search + " was found at " << index << endl; 
} else {
    cout << "The book " + book_to_search + " could not be found!!" << endl; 
}
cout << "The operation took " << time_taken.count() << endl; 

// Display first 20 books before sorting by rating 
cout << "\n Displaying first 20 books before sorting" << endl; 
display_books(books, 20); 

// Sorting the book title ratings using Selection Sort and measuring time taken to perform request
auto sort_start_time = chrono::high_resolution_clock::now(); 
selection_sort(books); 
auto sort_end_time = chrono::high_resolution_clock::now(); 
//I've made chrono::duration<double> to reduces headaches
Duration sort_time_taken = sort_end_time - sort_start_time; 

cout << "Books sorted by rating using selection sort." << endl;
cout << "Sorting took " << sort_time_taken.count() << " seconds." << endl;

// Display first 20 books after sorting by rating
cout << "\n---- Displaying the first 20 books by ratings ----" << endl;
display_books(books, 20);


return 0;
}



