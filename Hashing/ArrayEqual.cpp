#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkEqual(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    if (n != m)
        return false;

    unordered_map<int,int> hashMap;
    
    for(int x : a) {
        hashMap[x]++;
    }

    for(int y : b) {
        if(hashMap.find(y)==hashMap.end()) {
            return false;
        }
        if(hashMap[y]==0) {
            return false;
        }
        hashMap[y]--;
    }
    return true;
}

int main() {
    vector<int> a = { 3, 5, 2, 5, 2 };
    vector<int> b = { 2, 3, 5, 5, 2 };

    if (checkEqual(a, b))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    vector<int> c = { 1, 7, 1 };
    vector<int> d = { 7, 7, 1 };

    if (checkEqual(c, d))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}