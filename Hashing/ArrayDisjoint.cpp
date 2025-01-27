#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool areDisjoint(vector<int> a, vector<int> b) {
    bool result = true;
    unordered_set<int> hashSet(a.begin(),a.end());
    for(int i=0;i<b.size();i++) {
        if(hashSet.find(b.at(i))!=hashSet.end()) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    vector<int> a = {12, 34, 11, 9, 3}; 
    vector<int> b = {7, 2, 1, 5}; 
    
    if (areDisjoint(a, b))
        cout << "True"<<endl;
    else
        cout << "False"<<endl;
    vector<int> c = {2, 1, 3, 5}; 
    
    if (areDisjoint(a, c))
        cout << "True"<<endl;
    else
        cout << "False"<<endl;
    return 0;
}