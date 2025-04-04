#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <vector> 
#include <string>
#include <algorithm>

int binary_search(const std::vector<std::string> &arr, const std::string& target){
int start = 0; 
int size = arr.size();
int end = size-1; 
while (start <= end ){
    int mid = (start+end)/2;
    if (arr[mid] == target) return mid; 
    else if (target < arr[mid]){
        end = mid - 1;
    }
    else if (target > arr[mid]){
        start = mid + 1; 
    }
}
return -1; 
}
#endif //search_algorithms.h