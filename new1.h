#include <algorithm>
#include <iostream>
#include <string>
// using namespace std;
 
string array;

int main() {
 
    std::string array = "zabgqkzg";
 
    std::sort(array.begin(), array.end());
 
    for (int i = 0; i < sizeof(array); i++) {
        std::cout << array[i] << "\n";
    }
}