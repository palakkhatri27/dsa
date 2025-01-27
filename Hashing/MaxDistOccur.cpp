#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxDistance(vector<int> arr) {
    int dist = 0;
    unordered_map<int,int> hashMap;

    for(int i=0;i<arr.size();i++) {
        if(hashMap.find(arr.at(i))==hashMap.end()) {
            hashMap[arr.at(i)] = i;
        }
        else {
            dist = max(dist, i-hashMap[arr.at(i)]);
        }
    }

    return dist;
}

int main() {
    vector<int> arr0 {1, 1, 2, 2, 2, 1};
    cout << maxDistance(arr0) << endl;

    vector<int> arr1 {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    cout << maxDistance(arr1) << endl;

    vector<int> arr2 {1, 2, 3, 6, 5, 4};
    cout << maxDistance(arr2) << endl;
    return 0;
}