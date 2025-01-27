#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &v) {
    int i = 0, j = 1;
    while(i<v.size() && j<v.size()) {
        //Keep moving forward until you find the next unique element
        if(v.at(i) == v.at(j)) {
            if(v.at(i)==v.at(j)) {
                j++;
            }
        }
        //Unique element found
        else {
            v.at(i+1) = v.at(j);
            i++;
            j++;
        }
    }
    return i+1;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDuplicates(arr);
    for (int i = 0; i < newSize; i++) 
        cout << arr[i] << " ";
    return 0;
}