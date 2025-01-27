#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> v){
    //Assign last element of vector as a leader
    vector<int> l_leader_v = {v.back()};
    int i = v.size()-1;
    while(i>=0) {
        //If current element is greater than the last leader,
        //then it is greater than all elements to its right
        if(v[i]>l_leader_v.back()) {
            l_leader_v.push_back(v[i]);
        }
        //Else move on to v[i-1]
        else {
            i--;
        }
    }
    reverse(l_leader_v.begin(), l_leader_v.end());
    return l_leader_v;
}

int main() {
    vector<int> arr = { 16, 17, 4, 3, 5, 2 };
    vector<int> result = leaders(arr);
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}