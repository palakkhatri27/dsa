#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> result;
    unordered_set<int> hashSet(nums1.begin(),nums1.end());
    vector<int> res;

    for(int x : nums2) {
        if(result.find(x)==result.end() && hashSet.find(x)!=hashSet.end()) {
            result.insert(x);
        } 
    }
    copy(result.begin(), result.end(), std::back_inserter(res));
    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersection(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}