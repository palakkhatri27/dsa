// C++ program to demonstrate iterator behavior after
// vector::swap
#include <bits/stdc++.h>
using namespace std;

vector<int> getAlternates(vector<int> a) {
    int i = 0, j = 2;
    int len = a.size();
    while(i<len && (i+1)<len && (i+j)<len) {
        a[i+1] = a[i+j];
        i++;
        j++;
    }
    a.erase(a.begin()+i+1, a.end());
    return a;
}

int main() {
    vector<int> arr = {10, 20, 30};
    vector<int> res = getAlternates(arr); 
    for(int x: res)
        cout << x << " ";
    return 0;
}