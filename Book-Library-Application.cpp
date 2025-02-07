#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"  // Include the JSON library (nlohmann/json)

// Including my header file
#include "search_algorithms.h"

using json = nlohmann::json; 

// First we want to create a function to load the books into a vector 
// Here we pass the filename by reference so we can directly work with it 
std::vector<std::string> loadbooks(std::string& filename){
    // Here I'm opening the opening the file to read from 
    std::ifstream file(filename); 
    // Just as error flag incase there's an issue opening the file
    if (file.fail()){
        std::cout << "There was an issue opening the file";
    }
    // structure variable (Programmer defined data type)
    json booksJson; 
    //Reads the content of the file and parses it into valid Json using the library 
    file >> booksJson; 
    std::vector<std::string> books;
    for (const auto& book: booksJson){
        books.push_back(book["title"].get<std::string>());
    }
    return books;  
}

int main() {
   
    
    std::cout << "Hello World" << std::endl;

    return 0;
}