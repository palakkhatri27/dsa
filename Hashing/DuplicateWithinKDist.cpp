#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkDuplicatesWithinK(vector<int> arr, int k) {
    int dist = 0;
    unordered_map<int, int> hashMap;

    for(int i=0;i<arr.size();i++) {
        if(hashMap.find(arr.at(i))==hashMap.end()) {
            hashMap[arr.at(i)] = i;
        }
        else {
            if((i-hashMap[arr.at(i)])<=k) {
                return true;
            }
            hashMap[arr.at(i)] = i;
        }
    }

    return false;
}

int main ()
{
    vector<int> arr1 = {10, 5, 3, 4, 3, 5, 6};
    if (checkDuplicatesWithinK(arr1, 3))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5};
    if (checkDuplicatesWithinK(arr2, 3))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}