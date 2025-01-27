#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

bool isSubset(vector<int> a, vector<int> b) {
    bool result = true;
    unordered_set<int> hashSet(a.begin(),a.end());
    for(int i=0;i<b.size();i++) {
        if(hashSet.find(b.at(i))==hashSet.end()) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    vector<int> a = {11, 1, 13, 21, 3, 7};
    vector<int> b = {11, 3, 7, 1};
    if (isSubset(a, b)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    vector<int> c = {10, 5, 2, 23, 19};
    vector<int> d = {19, 5, 3};
    if (isSubset(c, d)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}